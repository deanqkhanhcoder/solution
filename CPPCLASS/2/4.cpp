#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MAXA = (int)1e6;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "MATONG"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    // code here
    // int n; cin >> n;
    // vector<int> a(n);
    // for (int &e : a) cin >> e;
    // vector<int> pwr(n + 1)
    // pwr[0] = 1;
    // for (int i = 1; i <= n; ++i){
    //     pwr[i] = (2 * pwr[i - 1]) % MOD; 
    // }
    // vector<int> 
    // for (int i = n; i >= 0;)
    int n; cin >> n;
    vector<int> cnt(MAXA + 1);
    for (int i = 1; i <= MAXA; ++i){
        for (int j = i; j <= MAXA; j += i){
            cnt[j]++;
        }
    }
    ll s = 0;
    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        s += 1LL * a * cnt[a];
    }
    cout << s << endl;
}