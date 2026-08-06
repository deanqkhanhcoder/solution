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
constexpr int MAXA = 7;
constexpr int LIMIT = 1 << MAXA;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int t; cin >> t;
    // while(t--){
    //     vector<int> u(MAXA);
    //     for (int &e : u) cin >> e;
    //     ll ans = 0;
    //     for (int mask = 1; mask < LIMIT; ++mask){
    //         int sum = 0;
    //         int cnt = 0;
    //         for (int i = 0; i < MAXA; ++i){
    //             if ((mask >> i) & 1){
    //                 sum += u[i];  
    //                 cnt++;
    //             } 
    //         }
    //         if (cnt & 1) ans += sum;
    //         else ans -= sum; 
    //     }
    //     cout << ans << endl;
    // }
    while (t--){
        vector<int> u(7);
        for (int &e : u) cin >> e;
        ll ans = 0;
        for (int i = 0; i < 3; ++i) ans += u[i];
        for (int i = 3; i < 6; ++i) ans -= u[i];
        ans += u[6];
        cout << ans << endl;
    }
    return 0;
}