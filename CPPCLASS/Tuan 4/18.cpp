#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MAXA = (int)2e8;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    static bitset<MAXA + 1> ip;
    vector<int> primes;
    ip.set();
    ip[0] = ip[1] = 0;
    for (int i = 2; i <= MAXA; ++i){
        if (ip[i]){
            primes.push_back(i);
        }
        for (int p : primes){
            if (1LL * i * p > MAXA) break;
            ip[i * p] = 0;
            if (i % p == 0) break; 
        }
    }
    int q; cin >> q;
    while (q--){
        int l, r; cin >> l >> r;
        auto it1 = upper_bound(primes.begin(), primes.end(), r);
        auto it2 = lower_bound(primes.begin(), primes.end(), l);
        cout << it1 - it2 << endl;
    }
    return 0;
}