// compare_multithread_primes.cpp
// Compile: g++ -O2 -std=gnu17 -pthread compare_multithread_primes.cpp -o compare_multithread
// Run: ./compare_multithread

#include <bits/stdc++.h>
#include <thread>
#include <atomic>
#include <mutex>
using namespace std;
using ll = long long;

static const ll NVAL = 1000000000000000000LL;
static const int K = 20;

// ---------------- helper gcd
ll gcdll(ll a, ll b){
    while (b){ ll t = a % b; a = b; b = t; }
    return a;
}

// ----------------- Miller-Rabin (deterministic for 64-bit)
using u128 = __uint128_t;
ll modmul(ll a, ll b, ll mod) {
    return (ll)((u128)a * (u128)b % (u128)mod);
}
ll modpow(ll a, ll d, ll mod) {
    ll res = 1;
    while (d) {
        if (d & 1) res = modmul(res, a, mod);
        a = modmul(a, a, mod);
        d >>= 1;
    }
    return res;
}
bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll p : {2LL,3LL,5LL,7LL,11LL,13LL,17LL,19LL,23LL,29LL,31LL,37LL}) {
        if (n % p == 0) return n == p;
    }
    ll d = n - 1;
    int s = 0;
    while ((d & 1) == 0) { d >>= 1; ++s; }
    // bases deterministic for 64-bit integers
    const ll bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (ll a : bases) {
        if (a % n == 0) continue;
        ll x = modpow(a % n, d, n);
        if (x == 1 || x == n-1) continue;
        bool composite = true;
        for (int r = 1; r < s; ++r) {
            x = modmul(x, x, n);
            if (x == n-1) { composite = false; break; }
            
        }
        if (composite) return false;
    }
    return true;
}

// ------------------------
// HÀM CHẠY "CODE CỦA HỌ" (giữ nguyên logic - bản dán, đóng gói)
// Không chỉnh sửa công thức của họ, chỉ đóng gói vào hàm
ll run_their_code(ll n, int k, const vector<ll> &primes_in){
    // giữ nguyên logic/hardcode
    vector<ll> primes = primes_in;
    vector<ll> sample = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
    if (n == 1000000000000000000LL && k == 20 && primes == sample) {
        return 872202319624080142LL;
    }
    vector< set<ll> > prods(k+1);
    function<void(int,int,ll)> back = [&](int ind, int used, ll prod){
        if (used && prod > 1) prods[used].insert(prod);
        if (ind == k) return;
        back(ind+1, used, prod);
        long double logprod = log((long double)prod);
        long double lp = log((long double)primes[ind]);
        if (logprod + lp <= log((long double)n) + 1e-12L) {
            if (prod <= n / primes[ind]) back(ind+1, used+1, prod * primes[ind]);
        }
    };
    back(0,0,1);
    ll ans = 0;
    for (int kk = 1; kk <= k; ++kk) {
        ll sum = 0;
        for (ll prod : prods[kk]) sum += n / prod;
        if (kk % 2 == 1) ans += sum; else ans -= sum;
    }
    return ans;
}

// ------------------------
// HÀM THAM CHIẾU (bitmask + lcm an toàn)
ll run_reference(ll n, int k, const vector<ll> &a){
    ll res = 0;
    int lim = 1 << k;
    for (int mask = 1; mask < lim; ++mask) {
        ll cur = 1;
        int bits = 0;
        bool over = false;
        for (int j = 0; j < k; ++j) if (mask & (1<<j)) {
            ++bits;
            ll g = gcdll(cur, a[j]);
            ll t = a[j] / g;
            if (t != 0 && cur > n / t) { over = true; break; }
            cur = cur * t;
            if (cur > n) { over = true; break; }
        }
        if (!over) {
            ll cnt = n / cur;
            if (bits & 1) res += cnt; else res -= cnt;
        }
    }
    return res;
}

// ------------------------
// Sinh tập prime bằng sieve (dùng cho nhiều testcase)
vector<int> sieve_primes(int LIMIT){
    vector<int> is(LIMIT+1,1);
    if (LIMIT < 1) return {};
    is[0]= (LIMIT>=0 ? 0:0);
    if (LIMIT>=1) is[1]=0;
    for (int p=2;p*(ll)p<=LIMIT;++p) if (is[p]) {
        for (int q=p*p;q<=LIMIT;q+=p) is[q]=0;
    }
    vector<int> out;
    for (int i=2;i<=LIMIT;++i) if (is[i]) out.push_back(i);
    return out;
}

// ------------------------
// helper: sample k distinct indices/elements from a source (without replacement)
// if src.size() <= k, return shuffled copy (may repeat if exactly equal - but we only call when src.size() >= k)
template<typename T>
vector<T> sample_distinct(const vector<T> &src, int k, mt19937_64 &rng){
    vector<T> out;
    if ((int)src.size() <= k) {
        out = src;
        shuffle(out.begin(), out.end(), rng);
        if ((int)out.size() > k) out.resize(k);
        // if smaller, we'll handle in ensure_unique later
        return out;
    }
    unordered_set<int> used;
    out.reserve(k);
    while ((int)out.size() < k) {
        int idx = (int)(rng() % src.size());
        if (used.insert(idx).second) out.push_back(src[idx]);
    }
    return out;
}

// ensure cand has exactly K distinct primes; use small_primes and larges as reservoirs to fill if needed
void ensure_unique_primes(vector<ll> &cand, const vector<int> &small_primes, const vector<ll> &larges, mt19937_64 &rng){
    unordered_set<ll> s;
    vector<ll> out;
    for (ll v : cand) {
        if (v <= 0) continue;
        if (!is_prime(v)) continue; // drop non-primes (extra safety)
        if (s.insert(v).second) out.push_back(v);
    }
    // fill until size K
    int si = 0;
    while ((int)out.size() < K) {
        // randomly choose from small_primes or larges
        if ((rng() & 1) && !larges.empty()) {
            ll pick = larges[rng() % larges.size()];
            if (s.insert(pick).second) out.push_back(pick);
        } else {
            int idx = (int)(rng() % small_primes.size());
            ll pick = (ll)small_primes[idx];
            if (s.insert(pick).second) out.push_back(pick);
        }
        // fallback if something weird happens: try sequentially through small_primes
        if ((int)out.size() < K) {
            for (int j = 0; j < (int)small_primes.size() && (int)out.size() < K; ++j) {
                ll pick = small_primes[(si + j) % small_primes.size()];
                if (s.insert(pick).second) out.push_back(pick);
            }
            si = (si + 37) % max(1, (int)small_primes.size());
        }
    }
    if ((int)out.size() > K) out.resize(K);
    // shuffle for variety
    shuffle(out.begin(), out.end(), rng);
    cand = out;
}

// ------------------------
// Sinh nhiều testcase "cực mạnh"
void build_strong_tries(vector<vector<ll>> &tries, mt19937_64 &rng, int PREGEN_TRIES = 3000){
    // base sets
    vector<ll> first20 = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
    tries.push_back(first20);
    auto rev = first20; reverse(rev.begin(), rev.end()); tries.push_back(rev);

    // many-large block near 1e9 (filter to primes)
    vector<ll> raw_larges = {
        1000000007LL,1000000009LL,1000000033LL,1000000087LL,1000000093LL,
        1000000097LL,1000000103LL,1000000123LL,1000000181LL,1000000207LL,
        1000000223LL,1000000241LL,1000000271LL,1000000289LL,1000000297LL,
        1000000321LL,1000000349LL,1000000363LL,1000000403LL,1000000409LL
    };
    vector<ll> larges;
    for (ll v : raw_larges) if (is_prime(v)) larges.push_back(v);
    // if by any chance larges filtered too small, add some safe large primes (fallbacks)
    if (larges.size() < 6) {
        // add some well-known primes
        for (ll v : {1000000007LL,1000000009LL,1000000033LL,1000000087LL,1000000093LL})
            if (is_prime(v)) larges.push_back(v);
        // dedupe
        sort(larges.begin(), larges.end());
        larges.erase(unique(larges.begin(), larges.end()), larges.end());
    }

    // add larges block (if fewer than 20, pad with small primes later)
    vector<ll> larges_block = larges;
    if ((int)larges_block.size() < K) {
        // will be fixed by ensure_unique_primes using small primes as reservoir
        while ((int)larges_block.size() < K) larges_block.push_back(larges_block.back());
    }
    tries.push_back(larges_block);

    // mix small + larges
    vector<ll> mix = first20;
    for (int i = 0; i < 6 && i < (int)larges.size(); ++i) mix[i+6] = larges[i];
    tries.push_back(mix);

    // prepare small primes up to 200k
    auto small_primes = sieve_primes(200000);
    int total_small = (int)small_primes.size();

    // sliding windows across small_primes
    int windows = min(400, max(50, total_small / 100));
    for (int s = 0; s < windows && (int)tries.size() < PREGEN_TRIES/3; ++s){
        int start = (s * 97) % max(1, total_small - 20);
        vector<ll> block;
        for (int i = 0; i < 20; ++i) block.push_back((ll)small_primes[(start + i) % total_small]);
        ensure_unique_primes(block, small_primes, larges, rng);
        tries.push_back(block);
    }

    // mid-range windows
    for (int s = 0; s < 200 && (int)tries.size() < PREGEN_TRIES*2/3; ++s){
        int start = (total_small/3 + s*11) % max(1, total_small - 20);
        vector<ll> block;
        for (int i = 0; i < 20; ++i) block.push_back((ll)small_primes[(start + i) % total_small]);
        ensure_unique_primes(block, small_primes, larges, rng);
        tries.push_back(block);
    }

    // permutations of first20 (many)
    auto perm = first20;
    for (int i = 0; i < 500 && (int)tries.size() < PREGEN_TRIES*4/5; ++i){
        shuffle(perm.begin(), perm.end(), rng);
        // permutation preserves distinctness and primality
        tries.push_back(perm);
    }

    // dense tiny primes sets (<=2000)
    vector<ll> tiny;
    for (int p : small_primes) if (p <= 2000) tiny.push_back(p);
    for (int s = 0; s < 200 && (int)tries.size() < PREGEN_TRIES; ++s){
        vector<ll> cand;
        int start = (s * 13) % max(1, (int)tiny.size()-20);
        for (int i = 0; i < 20; ++i) cand.push_back(tiny[(start + i) % tiny.size()]);
        ensure_unique_primes(cand, small_primes, larges, rng);
        tries.push_back(cand);
    }

    // mixed clusters: small + mid + large
    for (int s = 0; s < 400 && (int)tries.size() < PREGEN_TRIES; ++s){
        vector<ll> cand;
        int base1 = (s*17) % max(1,total_small-200);
        for (int i=0;i<8;i++) cand.push_back((ll)small_primes[base1 + i]);
        int base2 = (s*23 + 50) % max(1,total_small-200);
        for (int i=0;i<6;i++) cand.push_back((ll)small_primes[base2 + i + 20]);
        for (int i=0;i<6;i++) cand.push_back(larges[(s+i) % max(1,(int)larges.size())]);
        shuffle(cand.begin(), cand.end(), rng);
        ensure_unique_primes(cand, small_primes, larges, rng);
        tries.push_back(cand);
    }

    // add some explicit crafted pathological combos
    {
        vector<ll> path;
        for (int i=0;i<12;i++) path.push_back(first20[i]);
        for (int i=0;i<8;i++) path.push_back(larges[i % larges.size()]);
        ensure_unique_primes(path, small_primes, larges, rng);
        tries.push_back(path);
    }

    // random mixes until reach PREGEN_TRIES
    while ((int)tries.size() < PREGEN_TRIES){
        vector<ll> cand;
        int mode = rng() % 6;
        if (mode == 0){
            int start = rng() % max(1, total_small - 20);
            for (int i=0;i<20;i++) cand.push_back((ll)small_primes[start + i]);
        } else if (mode == 1){
            // 10 distinct smalls + 10 distinct larges
            auto s_part = sample_distinct(small_primes, 10, rng);
            auto l_part = sample_distinct(larges, 10, rng);
            for (auto x : s_part) cand.push_back((ll)x);
            for (auto x : l_part) cand.push_back(x);
            shuffle(cand.begin(), cand.end(), rng);
        } else if (mode == 2){
            auto l_part = sample_distinct(larges, 20, rng);
            for (auto x : l_part) cand.push_back(x);
        } else if (mode == 3){
            cand = first20;
            shuffle(cand.begin(), cand.end(), rng);
        } else if (mode == 4){
            int idx = rng() % max(1,total_small-20);
            for (int i=0;i<20;i++) cand.push_back((ll)small_primes[(idx + i*3) % total_small]);
        } else {
            for (int i=0;i<20;i++) cand.push_back((ll)small_primes[(i*7 + (int)(rng()%1000)) % total_small]);
        }
        ensure_unique_primes(cand, small_primes, larges, rng);
        tries.push_back(cand);
    }

    // remove duplicates (vector comparison)
    sort(tries.begin(), tries.end());
    tries.erase(unique(tries.begin(), tries.end()), tries.end());
}

// ------------------------
// Worker: đa luồng lấy testcase từ index atomics
struct Result {
    size_t idx;
    vector<ll> primes;
    ll their_ans;
    ll ref_ans;
};

void multithread_compare(const vector<vector<ll>> &tries, int THREADS, int RANDOM_ITER){
    atomic<size_t> idx(0);
    atomic<bool> found(false);
    mutex cout_mtx;
    size_t total = tries.size() + RANDOM_ITER;

    auto worker = [&](int tid, mt19937_64 rng) {
        size_t local;
        // first process pre-generated tries
        while (!found && (local = idx.fetch_add(1)) < tries.size()) {
            const vector<ll> &primes = tries[local];
            ll their_ans = run_their_code(NVAL, (int)primes.size(), primes);
            ll ref_ans = run_reference(NVAL, (int)primes.size(), primes);
            if (their_ans != ref_ans) {
                lock_guard<mutex> lk(cout_mtx);
                cout << "FOUND MISMATCH at pregen idx=" << local << "\n";
                cout << "primes:\n";
                for (ll v : primes) cout << v << " ";
                cout << "\n\ntheir_ans = " << their_ans << "\nref_ans   = " << ref_ans << "\n";
                found = true;
                return;
            }
            if ((local & 1023) == 0) {
                lock_guard<mutex> lk(cout_mtx);
                cerr << "[T" << tid << "] checked pregen " << local << "/" << tries.size() << "\n";
            }
        }
        // then random tries (index continues)
        while (!found) {
            size_t id = idx.fetch_add(1);
            if (id >= total) break;
            // map id to a random test
            vector<ll> primes;
            // create random mixed primes
            int mode = (int)(rng() % 7);
            // prepare some static larges and smalls (lazily)
            static vector<ll> larges_static = [](){
                vector<ll> raw = {
                    1000000007LL,1000000009LL,1000000033LL,1000000087LL,1000000093LL,
                    1000000097LL,1000000103LL,1000000123LL,1000000181LL,1000000207LL,
                    1000000223LL,1000000241LL,1000000271LL,1000000289LL,1000000297LL,
                    1000000321LL,1000000349LL,1000000363LL,1000000403LL,1000000409LL
                };
                vector<ll> out;
                for (ll v : raw) if (is_prime(v)) out.push_back(v);
                if (out.empty()) out.push_back(1000000007LL); // fallback
                return out;
            }();
            static vector<int> smalls_pre = [](){
                return sieve_primes(200000);
            }();
            int total_small = (int)smalls_pre.size();

            if (mode == 0){
                int start = (int)(rng() % max(1, total_small - 20));
                for (int i = 0; i < 20; ++i) primes.push_back(smalls_pre[start + i]);
            } else if (mode == 1){
                auto s_part = sample_distinct(smalls_pre, 10, rng);
                auto l_part = sample_distinct(larges_static, 10, rng);
                for (auto x : s_part) primes.push_back((ll)x);
                for (auto x : l_part) primes.push_back(x);
                shuffle(primes.begin(), primes.end(), rng);
            } else if (mode == 2){
                auto l_part = sample_distinct(larges_static, 20, rng);
                for (auto x : l_part) primes.push_back(x);
            } else if (mode == 3){
                int idx0 = (int)(rng() % total_small);
                for (int i = 0; i < 20; ++i) primes.push_back(smalls_pre[(idx0 + i*17) % total_small]);
            } else if (mode == 4){
                int idx0 = (int)(rng() % 500);
                for (int i = 0; i < 20; ++i) primes.push_back(smalls_pre[(idx0 + i) % 2000]);
            } else if (mode == 5){
                primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
                shuffle(primes.begin(), primes.end(), rng);
            } else {
                for (int i = 0; i < 7; ++i) primes.push_back(smalls_pre[rng()%total_small]);
                for (int i = 7; i < 14; ++i) primes.push_back(smalls_pre[(int)((rng()+1000)%total_small)]);
                for (int i = 14; i < 20; ++i) primes.push_back(larges_static[rng()%larges_static.size()]);
                shuffle(primes.begin(), primes.end(), rng);
            }

            // ensure distinct primes and primes only
            ensure_unique_primes(primes, smalls_pre, larges_static, rng);

            ll their_ans = run_their_code(NVAL, (int)primes.size(), primes);
            ll ref_ans = run_reference(NVAL, (int)primes.size(), primes);
            if (their_ans != ref_ans) {
                lock_guard<mutex> lk(cout_mtx);
                cout << "FOUND MISMATCH at random test id=" << id << "\n";
                cout << "primes:\n";
                for (ll v : primes) cout << v << " ";
                cout << "\n\ntheir_ans = " << their_ans << "\nref_ans   = " << ref_ans << "\n";
                found = true;
                return;
            }
            if ((id - tries.size()) % 5000 == 0) {
                lock_guard<mutex> lk(cout_mtx);
                cerr << "[T" << tid << "] checked random " << (id - tries.size()) << "/" << RANDOM_ITER << "\n";
            }
        }
    };

    // launch threads
    vector<thread> pool;
    for (int t = 0; t < THREADS; ++t){
        mt19937_64 myrng((uint64_t)chrono::high_resolution_clock::now().time_since_epoch().count() + t*1234567);
        pool.emplace_back(worker, t, myrng);
    }
    for (auto &th : pool) th.join();
    if (!found) cout << "No mismatch found in tried cases.\n";
}

// ------------------------
// main
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // tune these to make search stronger/longer
    const int PREGEN_TRIES = 200;   // number of strong pre-generated tries
    const int RANDOM_ITER = 120000;  // number of random tests to try after pregenerated
    int THREADS = (int)thread::hardware_concurrency();
    if (THREADS <= 0) THREADS = 4;
    if (THREADS > 12) THREADS = min(THREADS, 12); // cap threads to avoid oversubscribe

    mt19937_64 rng((uint64_t)chrono::high_resolution_clock::now().time_since_epoch().count());

    cerr << "[main] Building " << PREGEN_TRIES << " strong pre-generated tries...\n";
    vector<vector<ll>> tries;
    build_strong_tries(tries, rng, PREGEN_TRIES);
    cerr << "[main] Built tries count (after dedupe) = " << tries.size() << "\n";
    cerr << "[main] Running compare with THREADS = " << THREADS << ", RANDOM_ITER = " << RANDOM_ITER << "\n";

    multithread_compare(tries, THREADS, RANDOM_ITER);
    return 0;
}
