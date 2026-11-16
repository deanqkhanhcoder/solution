#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr ll INFLL = (ll)1e18;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n; cin >> n;
    constexpr int MAXA = (int)1e6;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<bool> isPrime(MAXA + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAXA; ++i){
        if (isPrime[i]){
            primes.push_back(i);
        }
        for (int p : primes){
            if (1LL * i * p > MAXA) break;
            isPrime[i * p] = false;
            if (i % p == 0) break; 
        }
    }
    ll pref = 0, maxest = -INFLL, minest = INFLL;
    for (int i = 0; i < n;++i){
        pref += a[i];
        if (isPrime[i + 1]){
            minest = min(minest, pref - a[i]);
            maxest = max(maxest, pref - minest);
        }
    }
    cout << maxest << endl;
    return 0;
}