// sort_benchmark.cpp
#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using u64 = uint64_t;
using steady = chrono::steady_clock;
using ms = chrono::duration<double, milli>;

// ---------- utility ----------
static inline double now_ms() {
    return chrono::duration<double, milli>(steady::now().time_since_epoch()).count();
}

void print_header(const string &s){
    cout << "\n=== " << s << " ===\n";
}

template<typename F>
double timeit(vector<u32> data, F f) {
    auto start = steady::now();
    f(data);
    auto end = steady::now();
    return chrono::duration<double>(end - start).count();
}

// ---------- data generation ----------
void generate_data(vector<u32> &a, size_t n, const string &dist) {
    a.resize(n);
    std::mt19937_64 rng(123456789);
    if (dist == "uniform") {
        uniform_int_distribution<u32> d(0, 1'000'000);
        for (size_t i=0;i<n;++i) a[i] = d(rng);
    } else if (dist == "smallrange") {
        // small range [0, 1000]
        uniform_int_distribution<u32> d(0, 1000);
        for (size_t i=0;i<n;++i) a[i] = d(rng);
    } else if (dist == "skewed") {
        // many small values, few large
        uniform_int_distribution<u32> d1(0, 1000);
        uniform_int_distribution<u32> d2(0, 10'000'000);
        for (size_t i=0;i<n;++i) {
            if (i % 10 == 0) a[i] = d2(rng);
            else a[i] = d1(rng);
        }
    } else if (dist == "nearly_sorted") {
        for (size_t i=0;i<n;++i) a[i] = (u32)i;
        // add some swaps
        uniform_int_distribution<size_t> d(0, n-1);
        for (size_t k=0;k< n/100; ++k) swap(a[d(rng)], a[d(rng)]);
    } else if (dist == "many_duplicates") {
        // only 100 distinct values
        uniform_int_distribution<u32> d(0,99);
        for (size_t i=0;i<n;++i) a[i] = d(rng);
    } else if (dist == "sparse") {
    // rải từ 1 đến 1e9
        uniform_int_distribution<u32> d(1, 1'000'000'000);
        for (size_t i=0;i<n;++i) a[i] = d(rng);
    } else {
        // default uniform
        uniform_int_distribution<u32> d(0, 1'000'000);
        for (size_t i=0;i<n;++i) a[i] = d(rng);
    }
}

// ---------- sorts ----------

// std::sort wrapper
void run_std_sort(vector<u32> &data) {
    sort(data.begin(), data.end());
}

// std::stable_sort wrapper
void run_std_stable_sort(vector<u32> &data) {
    stable_sort(data.begin(), data.end());
}

// Counting sort (non-negative ints). Guarded: if range too big, skip.
bool counting_sort_inplace(vector<u32> &a) {
    if (a.empty()) return true;
    u32 mn = a[0], mx = a[0];
    for (u32 x : a) { if (x < mn) mn = x; if (x > mx) mx = x; }
    u64 range = (u64)mx - (u64)mn + 1ULL;
    const u64 RANGE_LIMIT = 200'000'000ULL; // safety: ~200M counters -> ~800MB
    if (range > RANGE_LIMIT) return false;
    vector<u32> cnt((size_t)range);
    for (u32 x : a) cnt[x - mn]++;
    size_t idx = 0;
    for (u64 v=0; v<range; ++v) {
        u32 c = cnt[(size_t)v];
        while (c--) a[idx++] = (u32)(v + mn);
    }
    return true;
}

// Radix LSD generic for 32-bit unsigned with b bits per pass
void radix_lsd(vector<u32> &a, unsigned b) {
    if (a.empty()) return;
    const unsigned W = 32;
    unsigned passes = (W + b - 1) / b;
    const u32 mask = (b==32) ? 0xFFFFFFFFu : ((1u<<b)-1u);
    vector<u32> aux(a.size());
    for (unsigned pass = 0; pass < passes; ++pass) {
        size_t buckets = (size_t)1u << b;
        vector<size_t> cnt(buckets);
        unsigned shift = pass * b;
        // count
        for (u32 x : a) {
            size_t key = (x >> shift) & mask;
            cnt[key]++;
        }
        // prefix sum
        size_t sum = 0;
        for (size_t i=0;i<buckets;++i){
            size_t t = cnt[i]; cnt[i] = sum; sum += t;
        }
        // scatter (stable)
        for (u32 x : a) {
            size_t key = (x >> shift) & mask;
            aux[cnt[key]++] = x;
        }
        swap(a, aux);
    }
}

// Bucket sort for integers assuming relatively uniform distribution
void bucket_sort(vector<u32> &a, size_t bucket_count = 1000) {
    if (a.empty()) return;
    u32 mn = a[0], mx = a[0];
    for (u32 x : a) { mn = min(mn, x); mx = max(mx, x); }
    double range = double(mx) - double(mn) + 1.0;
    vector<vector<u32>> buckets(bucket_count);
    for (u32 x : a) {
        size_t idx = (size_t)((double(bucket_count) * (double(x) - double(mn))) / range);
        if (idx >= bucket_count) idx = bucket_count - 1;
        buckets[idx].push_back(x);
    }
    size_t pos = 0;
    for (auto &b : buckets) {
        sort(b.begin(), b.end());
        for (u32 v : b) a[pos++] = v;
    }
}

// Pigeonhole sort (like counting) - guard large ranges
bool pigeonhole_sort(vector<u32> &a) {
    return counting_sort_inplace(a); // identical for integers
}

// Flashsort implementation (classical version)
// Note: sensitive to distributions; works well for near-uniform.
bool flashsort(vector<u32> &arr) {
    size_t n = arr.size();
    if (n < 2) return true;
    u32 mn = arr[0], mx = arr[0];
    for (u32 v : arr) { if (v < mn) mn = v; if (v > mx) mx = v; }
    if (mn == mx) return true;
    // choose m ~ 0.43*n (empirical)
    size_t m = max<size_t>(2, (size_t)(0.43 * n));
    vector<size_t> cls(m);
    double c1 = (double)(m - 1) / (double)(mx - mn);
    for (u32 v : arr) {
        size_t k = (size_t)( (v - mn) * c1 );
        if (k >= m) k = m - 1;
        cls[k]++;
    }
    for (size_t i=1;i<m;++i) cls[i] += cls[i-1];
    // permute
    size_t moves = 0;
    size_t j = 0;
    size_t k = m - 1;
    while (moves < n) {
        while (j >= cls[k]) {
            ++j;
            k = (size_t)( (arr[j] - mn) * c1 );
            if (k >= m) k = m - 1;
        }
        u32 ev = arr[j];
        while (j < cls[k]) {
            k = (size_t)( (ev - mn) * c1 );
            if (k >= m) k = m - 1;
            size_t dest = --cls[k];
            std::swap(ev, arr[dest]);
            ++moves;
        }
    }
    // insertion sort to finish
    for (size_t i=1;i<n;++i) {
        u32 key = arr[i];
        ssize_t j2 = (ssize_t)i - 1;
        while (j2 >= 0 && arr[j2] > key) { arr[j2+1] = arr[j2]; --j2; }
        arr[j2+1] = key;
    }
    return true;
}

// Burstsort note: it is primarily a string-sorting algorithm (trie-based bursts).
// Not implemented for integers here. If you want, we can implement a string-burstsort
// and run it on stringified numbers, but that will be extremely slow and memory heavy
// for n = 1e7. So we omit burstsort from integer benchmark.

// ---------- verification ----------
bool is_sorted_vec(const vector<u32> &a) {
    for (size_t i=1;i<a.size();++i) if (a[i-1] > a[i]) return false;
    return true;
}

// ---------- main ----------
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n = 10'000'000;
    string dist = "uniform";
    if (argc >= 2) n = stoull(argv[1]);
    if (argc >= 3) dist = argv[2];

    cout << "Benchmark sorts on n = " << n << ", distribution = " << dist << "\n";
    cout << "Warning: make sure you have sufficient RAM. Compiling with -O3 recommended.\n";

    // generate base data
    vector<u32> base;
    {
        cout << "Generating data...\n";
        generate_data(base, n, dist);
    }
    cout << "Data generated. sample: " << base[0] << ", " << base[min<size_t>(n-1,5)] << "\n";

    vector<pair<string, double>> results;

    // helper lambda to run and verify
    auto run_and_record = [&](const string &name, function<bool(vector<u32>&)> f_bool, function<void(vector<u32>&)> f_void = nullptr) {
        vector<u32> data = base; // copy before timing
        cout << "Running " << name << " ... " << flush;
        auto start = steady::now();
        bool ok = true;
        if (f_void) {
            f_void(data);
        } else {
            ok = f_bool(data);
        }
        auto end = steady::now();
        double secs = chrono::duration<double>(end - start).count();
        bool sorted = ok ? is_sorted_vec(data) : false;
        cout << (ok ? "done" : "skipped") << " | time = " << secs << " s"
             << " | sorted? " << (sorted ? "YES" : (ok ? "NO" : "SKIPPED")) << "\n";
        if (ok) results.emplace_back(name, secs);
    };

    // std::sort
    run_and_record("std::sort (introsort)", nullptr, [&](vector<u32> &d){ run_std_sort(d); });

    // std::stable_sort
    run_and_record("std::stable_sort (merge sort)", nullptr, [&](vector<u32> &d){ run_std_stable_sort(d); });

    // Counting sort
    run_and_record("Counting sort (O(n + k))", [](vector<u32> &d){ return counting_sort_inplace(d); });

    // Radix sorts
    run_and_record("Radix sort base 2^8 (4 passes)", nullptr, [&](vector<u32> &d){ radix_lsd(d, 8); });
    run_and_record("Radix sort base 2^15 (3 passes)", nullptr, [&](vector<u32> &d){ radix_lsd(d, 15); });
    run_and_record("Radix sort base 2^16 (2 passes)", nullptr, [&](vector<u32> &d){ radix_lsd(d, 16); });

    // Bucket sort
    run_and_record("Bucket sort (1000 buckets)", nullptr, [&](vector<u32> &d){ bucket_sort(d, 1000); });

    // Pigeonhole sort
    run_and_record("Pigeonhole sort", [](vector<u32> &d){ return pigeonhole_sort(d); });

    // Flashsort
    run_and_record("Flashsort", [](vector<u32> &d){ return flashsort(d); });

    // Summary
    cout << "\n--- Summary (successful runs) ---\n";
    for (auto &p : results) {
        cout << p.first << " : " << p.second << " s\n";
    }
    cout << "Note: Burstsort omitted (string algorithm). Counting/Pigeonhole are skipped if range too large.\n";
    cout << "Done.\n";
    return 0;
}
