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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a(n);
        int idx = 0;
        for (pair<int, int> &p : a){
            cin >> p.first;
            p.second = idx++;
        }
        sort(all(a));
        int ans_i = a[0].second, ans_j = a[1].second; 
        int min_xor = a[0].first ^ a[1].first;
        int val = a[0].first;
        for (int i = 1; i < n - 1; ++i){
            int val_i = a[i].first;
            int val_j = a[i + 1].first;
            int cur_xor = val_i ^ val_j;
            if (cur_xor < min_xor){
                min_xor = cur_xor;
                ans_i = a[i].second;
                ans_j = a[i + 1].second;
                val = val_i;
            }
        }
        int x = ((1LL << k) - 1) ^ val;
        ans_i++;
        ans_j++;
        cout << ans_i << ' ' << ans_j << ' ' << x << endl;
    }
    return 0;
}