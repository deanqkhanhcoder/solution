#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// -----------------------------
// 1) HÀM CHẠY "CODE CỦA BẠN" (bitmask + lcm an toàn)
// -----------------------------
ll gcdll(ll a, ll b){
    while(b){ ll t = a % b; a = b; b = t; }
    return a;
}
ll lcm_user(ll x, ll y, ll n){
    ll g = gcdll(x, y);
    if (x > n / (y / g)) return n + 1;
    return x * (y / g);
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
// 2) HÀM CHẠY "CODE CỦA HỌ" (giữ nguyên logic hardcode + backtracking)
// -----------------------------
ll run_their_code(ll n, int k, const vector<ll> &primes_in){
    vector<ll> primes = primes_in;
    vector<ll> sample = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
    if (n == 1000000000000000000LL && k == 20 && primes == sample) {
        return 872202319624080142LL;
    }
    vector< set<ll> > prods(k+1);
    function<void(ll,ll,ll)> back = [&](ll ind, ll used, ll prod){
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
// 3) HÀM THAM CHIẾU CHUẨN (bitmask + lcm an toàn)
// -----------------------------
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
            if (cur > n / t) { over = true; break; }
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
// 4) Helpers: generate primes & testcases
// -----------------------------
vector<ll> first20_primes(){
    return {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
}
vector<ll> generate_small_primes(int need){
    int limit = 5000;
    vector<int> is(limit+1,1); is[0]=is[1]=0;
    vector<ll> p;
    for (int i=2;i<=limit;i++) if (is[i]){
        p.push_back(i);
        if ((ll)i*i <= limit) for (int j=i*i;j<=limit;j+=i) is[j]=0;
    }
    if ((int)p.size() < need) return p;
    p.resize(need);
    return p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll N = 1000000000000000000LL;
    mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

    vector<vector<ll>> tries;
    // deterministic tries
    vector<ll> f20 = first20_primes();
    tries.push_back(f20);
    auto rev = f20; reverse(rev.begin(), rev.end()); tries.push_back(rev);
    auto swap12 = f20; swap(swap12[0], swap12[1]); tries.push_back(swap12);
    vector<ll> mix = {2,3,5,7,11,13,1000000007LL,1000000009LL,1000000033LL,17,19,23,29,31,37,41,43,47,53,59};
    tries.push_back(mix);
    vector<ll> larges = {
        1000000007LL,1000000009LL,1000000033LL,1000000087LL,1000000093LL,
        1000000097LL,1000000103LL,1000000123LL,1000000181LL,1000000207LL,
        1000000223LL,1000000241LL,1000000271LL,1000000289LL,1000000297LL,
        1000000321LL,1000000349LL,1000000363LL,1000000403LL,1000000409LL
    };
    tries.push_back(larges);
    auto p2 = f20; shuffle(p2.begin(), p2.end(), rng); tries.push_back(p2);

    // random generation (limited amount)
    vector<ll> smalls = generate_small_primes(200);
    for (int t=0; t<1000; ++t){
        int mode = rng() % 5;
        vector<ll> cand;
        if (mode == 0){
            shuffle(smalls.begin(), smalls.end(), rng);
            for (int i=0;i<20;i++) cand.push_back(smalls[i]);
        } else if (mode == 1){
            shuffle(smalls.begin(), smalls.end(), rng);
            auto big = larges; shuffle(big.begin(), big.end(), rng);
            for (int i=0;i<10;i++) cand.push_back(smalls[i]);
            for (int i=0;i<10;i++) cand.push_back(big[i]);
            shuffle(cand.begin(), cand.end(), rng);
        } else if (mode == 2){
            auto big = larges; shuffle(big.begin(), big.end(), rng);
            for (int i=0;i<20;i++) cand.push_back(big[i % big.size()]);
            shuffle(cand.begin(), cand.end(), rng);
        } else if (mode == 3){
            cand = f20; shuffle(cand.begin(), cand.end(), rng);
        } else {
            cand = f20; cand[0] = larges[rng() % larges.size()];
            shuffle(cand.begin()+1, cand.end(), rng);
        }
        tries.push_back(cand);
    }

    cerr << "[debug] Total pre-generated tries: " << tries.size() << "\n";
    auto t_start_all = chrono::high_resolution_clock::now();

    // run deterministic + random tries
    for (size_t idx = 0; idx < tries.size(); ++idx){
        auto primes = tries[idx];
        int k = (int)primes.size();
        if (k == 0 || k > 20) continue;
        auto t0 = chrono::high_resolution_clock::now();
        cerr << "[debug] Running test " << idx+1 << "/" << tries.size() << " (k=" << k << ") ... "; cerr.flush();

        ll user_ans = run_user_code(N, k, primes);
        ll their_ans = run_their_code(N, k, primes);
        ll ref_ans = run_reference(N, k, primes);

        auto t1 = chrono::high_resolution_clock::now();
        double dt = chrono::duration<double>(t1 - t0).count();
        cerr << "done in " << fixed << setprecision(3) << dt << "s\n"; cerr.flush();

        if (their_ans != ref_ans || user_ans != ref_ans || their_ans != user_ans){
            cout << "FOUND MISMATCH\n";
            cout << "n = " << N << " k = " << k << "\n";
            cout << "primes:\n";
            for (ll v : primes) cout << v << " ";
            cout << "\n\nuser_ans = " << user_ans << "\n";
            cout << "their_ans = " << their_ans << "\n";
            cout << "ref_ans = " << ref_ans << "\n";
            cerr << "[debug] MISMATCH at test index " << idx+1 << "\n";
            return 0;
        }
    }

    auto t_mid = chrono::high_resolution_clock::now();
    double dt_mid = chrono::duration<double>(t_mid - t_start_all).count();
    cerr << "[debug] Finished pre-generated tries in " << fixed << setprecision(3) << dt_mid << "s\n";

    // random search loop with periodic debug
    cerr << "[debug] Starting random search loop (up to 200000 iterations)...\n";
    for (int iter = 0; iter < 200000; ++iter) {
        if (iter % 1000 == 0) {
            cerr << "[debug] random iter = " << iter << "\n";
            cerr.flush();
        }
        vector<ll> primes;
        int mode = rng() % 5;
        if (mode == 0) {
            shuffle(smalls.begin(), smalls.end(), rng);
            for (int i = 0; i < 20; ++i) primes.push_back(smalls[i]);
        } else if (mode == 1) {
            auto big = larges; shuffle(big.begin(), big.end(), rng);
            for (int i = 0; i < 10; ++i) primes.push_back(smalls[i]);
            for (int i = 0; i < 10; ++i) primes.push_back(big[i]);
            shuffle(primes.begin(), primes.end(), rng);
        } else if (mode == 2) {
            auto big = larges; shuffle(big.begin(), big.end(), rng);
            for (int i = 0; i < 20; ++i) primes.push_back(big[i % big.size()]);
            shuffle(primes.begin(), primes.end(), rng);
        } else if (mode == 3) {
            primes = f20;
            shuffle(primes.begin(), primes.end(), rng);
        } else {
            primes = f20;
            primes[0] = larges[rng() % larges.size()];
            shuffle(primes.begin()+1, primes.end(), rng);
        }

        ll user_ans = run_user_code(N, 20, primes);
        ll their_ans = run_their_code(N, 20, primes);
        ll ref_ans = run_reference(N, 20, primes);

        if (their_ans != ref_ans || user_ans != ref_ans || their_ans != user_ans){
            cout << "FOUND MISMATCH\n";
            cout << "n = " << N << " k = 20\n";
            cout << "primes:\n";
            for (ll v : primes) cout << v << " ";
            cout << "\n\nuser_ans = " << user_ans << "\n";
            cout << "their_ans = " << their_ans << "\n";
            cout << "ref_ans = " << ref_ans << "\n";
            cerr << "[debug] MISMATCH at random iter " << iter << "\n";
            return 0;
        }
    }

    cerr << "[debug] Random search finished without mismatch (increase iterations to try more)\n";
    cout << "No mismatch found in tried cases.\n";
    return 0;
}
