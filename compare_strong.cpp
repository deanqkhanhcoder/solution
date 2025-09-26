// compare_strong_fixed.cpp
// Fix: replace deprecated random_shuffle with std::shuffle
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// -----------------------------
// Helper: gcd
ll gcdll(ll a, ll b){
    while (b){ ll t = a % b; a = b; b = t; }
    return a;
}

// -----------------------------
// 1) HÀM CHẠY "CODE CỦA BẠN" (bitmask + lcm an toàn)
// Giữ nguyên logic (đóng gói)
ll lcm_user(ll x, ll y, ll n){
    ll g = gcdll(x, y);
    // tránh overflow: kiểm tra x * (y/g) > n
    ll t = y / g;
    if (t != 0 && x > n / t) return n + 1;
    return x * t;
}
ll run_user_code(ll n, int k, const vector<ll> &a){
    int size = 1 << k;
    ll res = 0;
    for (int m = 1; m < size; ++m){
        bool over = false;
        ll clcm = 1;
        int cnt = 0;
        for (int j = 0; j < k; ++j){
            if (m & (1 << j)){
                cnt++;
                clcm = lcm_user(clcm, a[j], n);
                if (clcm > n) { over = true; break; }
            }
        }
        if (!over){
            ll p = n / clcm;
            if (cnt & 1) res += p;
            else res -= p;
        }
    }
    return res;
}

// -----------------------------
// 2) HÀM CHẠY "CODE CỦA HỌ" (backtracking + hardcode) - nguyên bản logic đóng gói
ll run_their_code(ll n, int k, const vector<ll> &primes_in){
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

// -----------------------------
// 3) HÀM THAM CHIẾU CHUẨN (bitmask + lcm an toàn) - để kiểm chứng
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

// -----------------------------
// 4) Sinh prime list (sieve đến LIMIT) để tạo testcase mạnh
vector<int> sieve_primes(int LIMIT){
    vector<int> is(LIMIT+1,1);
    is[0]=is[1]=0;
    for (int p=2;p*p<=LIMIT;++p) if (is[p]){
        for (int q=p*p;q<=LIMIT;q+=p) is[q]=0;
    }
    vector<int> out;
    for (int i=2;i<=LIMIT;++i) if (is[i]) out.push_back(i);
    return out;
}

// -----------------------------
// Build many strong testcases
void build_strong_tries(vector<vector<ll>> &tries){
    // create a local RNG for shuffle
    static std::mt19937_64 rng(1234567);

    // constants
    const int K = 20;
    // first 20 small primes
    vector<ll> first20 = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
    tries.push_back(first20);

    // reversed
    auto rev = first20; reverse(rev.begin(), rev.end()); tries.push_back(rev);

    // swapped pairs
    auto sw = first20;
    swap(sw[0], sw[5]); swap(sw[1], sw[7]); tries.push_back(sw);

    // mix small + large fixed
    vector<ll> mix = {2,3,5,7,11,13,1000000007LL,1000000009LL,1000000033LL,17,19,23,29,31,37,41,43,47,53,59};
    tries.push_back(mix);

    // many large primes near 1e9
    vector<ll> larges = {
        1000000007LL,1000000009LL,1000000033LL,1000000087LL,1000000093LL,
        1000000097LL,1000000103LL,1000000123LL,1000000181LL,1000000207LL,
        1000000223LL,1000000241LL,1000000271LL,1000000289LL,1000000297LL,
        1000000321LL,1000000349LL,1000000363LL,1000000403LL,1000000409LL
    };
    tries.push_back(larges);

    // extreme: first20 but with one big element at front
    auto f20_bigfront = first20;
    f20_bigfront[0] = 1000000007LL;
    tries.push_back(f20_bigfront);

    // build sliding windows from small primes up to limit
    int LIMIT = 200000; // sieve to 200k (gives many primes)
    auto small_primes = sieve_primes(LIMIT);
    int total_small = (int)small_primes.size();
    // add sliding windows of 20 primes (start positions)
    int windows = min(200, max(20, total_small / 50)); // limit number of windows
    for (int s = 0; s < windows; ++s){
        int start = s * max(1, (total_small - 20) / windows);
        vector<ll> block;
        for (int i = 0; i < 20; ++i) block.push_back((ll)small_primes[(start + i) % total_small]);
        tries.push_back(block);
    }

    // add windows from mid-range primes (shifted start)
    for (int s = 0; s < 80; ++s){
        int start = (total_small/2 + s*3) % (total_small-20);
        vector<ll> block;
        for (int i = 0; i < 20; ++i) block.push_back((ll)small_primes[(start + i) % total_small]);
        tries.push_back(block);
    }

    // sample primes spread across list (pick every step)
    for (int step = 1; step <= 50; step += 7){
        vector<ll> cand;
        int idx = 0;
        for (int i = 0; i < 20; ++i){
            cand.push_back((ll)small_primes[(idx) % total_small]);
            idx = (idx + step*3 + 13) % total_small;
        }
        tries.push_back(cand);
    }

    // combos: take small primes but replace some by larges, many patterns
    for (int t = 0; t < 40; ++t){
        vector<ll> cand = first20;
        // deterministically replace positions by large primes
        int p = (t % 5) + 1;
        for (int i = 0; i < p; ++i) cand[(i*3 + t) % 20] = larges[(i*7 + t) % larges.size()];
        tries.push_back(cand);
    }

    // permutations and shuffles of first20
    auto perm = first20;
    for (int i = 0; i < 120; ++i){
        shuffle(perm.begin(), perm.end(), rng); // replaced random_shuffle
        tries.push_back(perm);
    }

    // sliding blocks from larger sieve segments to get primes ~1e5..2e5
    for (int s = 0; s < 200; ++s){
        int offset = (s * 17 + 37) % (max(100, total_small - 20));
        vector<ll> cand;
        for (int i = 0; i < 20; ++i) cand.push_back((ll)small_primes[offset + i]);
        tries.push_back(cand);
    }

    // create 'dense multiplicative' sets: pick very small primes (so many subsets product <= 1e18)
    vector<ll> tiny;
    for (int p = 0; p < (int)small_primes.size() && tiny.size() < 60; ++p){
        if (small_primes[p] <= 2000) tiny.push_back(small_primes[p]);
    }
    // make combinations of 20 from tiny sliding
    for (int s = 0; s < 40; ++s){
        vector<ll> cand;
        int start = s % max(1, (int)tiny.size()-20);
        for (int i = 0; i < 20; ++i) cand.push_back(tiny[(start + i) % tiny.size()]);
        tries.push_back(cand);
    }

    // mixed clusters: groups of primes around different magnitudes combined
    for (int s = 0; s < 60; ++s){
        vector<ll> cand;
        // 7 small, 7 mid, 6 large
        int baseSmall = (s*3) % max(1, total_small-100);
        int baseMid = (s*7 + 23) % max(1, total_small-200);
        for (int i = 0; i < 7; ++i) cand.push_back(small_primes[(baseSmall + i) % total_small]);
        for (int i = 0; i < 7; ++i) cand.push_back(small_primes[(baseMid + 50 + i) % total_small]);
        for (int i = 0; i < 6; ++i) cand.push_back(larges[(i*5 + s) % larges.size()]);
        tries.push_back(cand);
    }

    // some crafted pathological cases:
    vector<ll> path;
    for (int i = 0; i < 12; ++i) path.push_back(first20[i]);
    for (int i = 0; i < 8; ++i) path.push_back(larges[i]);
    tries.push_back(path);

    // finally add some random mixes to increase coverage
    for (int t = 0; t < 1200; ++t){
        vector<ll> cand;
        int mode = t % 6;
        if (mode == 0){
            // pick 20 random small primes
            int start = (t*37) % max(1, total_small - 20);
            for (int i = 0; i < 20; ++i) cand.push_back((ll)small_primes[start + i]);
        } else if (mode == 1){
            // mix 10 small + 10 large
            int start = (t*13) % max(1, total_small - 10);
            for (int i = 0; i < 10; ++i) cand.push_back((ll)small_primes[start + i]);
            for (int i = 0; i < 10; ++i) cand.push_back(larges[(t + i) % larges.size()]);
            shuffle(cand.begin(), cand.end(), rng); // replaced random_shuffle
        } else if (mode == 2){
            // spaced picks from small_primes
            int idx = (t*29) % total_small;
            for (int i = 0; i < 20; ++i){
                cand.push_back((ll)small_primes[(idx + i*11) % total_small]);
            }
        } else if (mode == 3){
            // mostly large
            for (int i = 0; i < 20; ++i) cand.push_back(larges[(t + i) % larges.size()]);
        } else if (mode == 4){
            // first20 but shuffle with big inserted
            cand = first20;
            shuffle(cand.begin(), cand.end(), rng); // replaced random_shuffle
            cand[(t*7)%20] = larges[t % larges.size()];
        } else {
            // a few very small primes repeated pattern
            for (int i = 0; i < 20; ++i) cand.push_back((ll)small_primes[(i*3 + t) % total_small]);
        }
        tries.push_back(cand);
    }

    // remove duplicates (vector equal)
    sort(tries.begin(), tries.end());
    tries.erase(unique(tries.begin(), tries.end()), tries.end());
}

// -----------------------------
// Main: chạy các testcase, debug progress
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll NVAL = 1000000000000000000LL;
    vector<vector<ll>> tries;
    build_strong_tries(tries);

    cerr << "[debug] Built tries count = " << tries.size() << "\n";
    cerr << "[debug] Starting comparison on " << tries.size() << " pre-generated cases.\n";

    // run pre-generated tries
    for (size_t idx = 0; idx < tries.size(); ++idx){
        auto primes = tries[idx];
        int k = (int)primes.size();
        if (k != 20) continue; // our generation aims for 20
        cerr << "[debug] Test " << idx+1 << "/" << tries.size() << " ... ";
        cerr.flush();

        auto t0 = chrono::high_resolution_clock::now();
        ll user_ans = run_user_code(NVAL, k, primes);
        ll their_ans = run_their_code(NVAL, k, primes);
        ll ref_ans = run_reference(NVAL, k, primes);
        auto t1 = chrono::high_resolution_clock::now();
        double dt = chrono::duration<double>(t1 - t0).count();

        cerr << "done (" << fixed << setprecision(3) << dt << "s)\n";
        if (their_ans != ref_ans || user_ans != ref_ans || their_ans != user_ans){
            cout << "FOUND MISMATCH\n";
            cout << "n = " << NVAL << " k = " << k << "\n";
            cout << "primes:\n";
            for (ll v : primes) cout << v << " ";
            cout << "\n\nuser_ans = " << user_ans << "\n";
            cout << "their_ans = " << their_ans << "\n";
            cout << "ref_ans = " << ref_ans << "\n";
            cerr << "[debug] MISMATCH at test index " << idx+1 << "\n";
            return 0;
        }
    }

    cerr << "[debug] Pre-generated tries done. Now random search (strong strategies)...\n";

    // random search loops (various strategies)
    mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    vector<ll> large_primes = {
        1000000007LL,1000000009LL,1000000033LL,1000000087LL,1000000093LL,
        1000000097LL,1000000103LL,1000000123LL,1000000181LL,1000000207LL,
        1000000223LL,1000000241LL,1000000271LL,1000000289LL,1000000297LL,
        1000000321LL,1000000349LL,1000000363LL,1000000403LL,1000000409LL
    };

    // prepare a small primes list for sampling
    auto small_primes_full = sieve_primes(200000);
    int total_small = (int)small_primes_full.size();

    int RANDOM_ITER = 200000;
    for (int iter = 0; iter < RANDOM_ITER; ++iter){
        if (iter % 5000 == 0) {
            cerr << "[debug] random iter = " << iter << "/" << RANDOM_ITER << "\n";
            cerr.flush();
        }
        vector<ll> primes;
        int mode = rng() % 7;
        if (mode == 0){
            // 20 random small primes contiguous
            int start = rng() % max(1, total_small - 20);
            for (int i = 0; i < 20; ++i) primes.push_back(small_primes_full[start + i]);
        } else if (mode == 1){
            // mix 8 small + 6 mid + 6 large
            int start = rng() % max(1, total_small - 1000);
            for (int i = 0; i < 8; ++i) primes.push_back(small_primes_full[(start + i) % total_small]);
            for (int i = 0; i < 6; ++i) primes.push_back(small_primes_full[(start + 100 + i) % total_small]);
            for (int i = 0; i < 6; ++i) primes.push_back(large_primes[rng() % large_primes.size()]);
            shuffle(primes.begin(), primes.end(), rng);
        } else if (mode == 2){
            // mostly large
            for (int i = 0; i < 20; ++i) primes.push_back(large_primes[rng() % large_primes.size()]);
        } else if (mode == 3){
            // spaced picks
            int idx = rng() % total_small;
            for (int i = 0; i < 20; ++i) primes.push_back(small_primes_full[(idx + i*17) % total_small]);
        } else if (mode == 4){
            // pick many small primes <= 1000 (dense multiplicative)
            int idx = rng() % 200;
            for (int i = 0; i < 20; ++i) primes.push_back(small_primes_full[(idx + i) % 2000]);
        } else if (mode == 5){
            // permutation of first20
            primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
            shuffle(primes.begin(), primes.end(), rng);
        } else {
            // random mix from various ranges
            for (int i = 0; i < 7; ++i) primes.push_back(small_primes_full[rng() % total_small]);
            for (int i = 7; i < 14; ++i) primes.push_back(small_primes_full[(rng() + 1000) % total_small]);
            for (int i = 14; i < 20; ++i) primes.push_back(large_primes[rng() % large_primes.size()]);
            shuffle(primes.begin(), primes.end(), rng);
        }

        ll user_ans = run_user_code(NVAL, 20, primes);
        ll their_ans = run_their_code(NVAL, 20, primes);
        ll ref_ans = run_reference(NVAL, 20, primes);
        if (their_ans != ref_ans || user_ans != ref_ans || their_ans != user_ans){
            cout << "FOUND MISMATCH\n";
            cout << "n = " << NVAL << " k = 20\n";
            cout << "primes:\n";
            for (ll v : primes) cout << v << " ";
            cout << "\n\nuser_ans = " << user_ans << "\n";
            cout << "their_ans = " << their_ans << "\n";
            cout << "ref_ans = " << ref_ans << "\n";
            cerr << "[debug] MISMATCH at random iter " << iter << "\n";
            return 0;
        }
    }

    cerr << "[debug] Random search finished without mismatch (increase RANDOM_ITER to try more)\n";
    cout << "No mismatch found in tried cases.\n";
    return 0;
}
