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
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    ll cost1 = 0, cost2 = 0;
    ll S1 = 0, S2 = 0;
    for (int i = 0; i < n; ++i){
        S1 += a[i];
        S2 += a[i];
        if (i % 2 == 0){
            if (S1 <= 0){
                cost1 += 1 - S1;
                S1 = 1;
            }
            if (S2 >= 0){
                cost2 += 1 + S2;
                S2 = -1;
            }
        } else {
            if (S1 >= 0){
                cost1 += 1 + S1;
                S1 = -1;
            }
            if (S2 <= 0){
                cost2 += 1 - S2;
                S2 = 1;
            }
        }
    }
    cout << min(cost1, cost2) << endl;
    return 0;
}