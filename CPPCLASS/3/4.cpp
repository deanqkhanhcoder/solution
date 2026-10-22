#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    constexpr int MAXN = (int)1e5;
    vector<int> spf(MAXN + 1, 0);
    vector<int> primes;
    for (int i = 2; i <= MAXN; ++i){
        if (spf[i] == 0){
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes){
            if (1LL * i * p > MAXN) break;
            spf[i * p] = p;
            if (spf[i] == p) break;
        }
    }
    vector<bool> is_factor(MAXN + 1, false);
    for (int x : a){
        while (x > 1){
            int p = spf[x];
            while (x % p == 0) x /= p;
            is_factor[p] = true;
        }
    }
    vector<int> factor;
    for (int i = 1; i <= MAXN; ++i) if (is_factor[i]) factor.push_back(i);
    vector<bool> check(m + 1, true);
    check[0] = false;
    for (int x : factor){
        for (int i = x; i <= m; i += x){
            check[i] = false;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) if (check[i]) ans++;
    cout << ans << endl;
    for (int i = 1; i <= m; ++i){
        if (check[i]) cout << i << endl;
    }
    return 0;
}