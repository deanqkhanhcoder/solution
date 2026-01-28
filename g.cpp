#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s; cin >> n >> s;
    vector<pair<int, int>> wv;
    for (int i = 0; i < n; ++i){
        int w, v, a;
        cin >> w >> v >> a;
        int base = 1;
        while (a > 0){
            if (base > a){
                wv.push_back({w * a, v * a});
                break;
            }
            a -= base;
            wv.push_back({w * base, v * base});
            base <<= 1;
        }
    }
    int m = wv.size();
    vector<int> dp(s + 1, 0);
    for (int i = 0; i < m; ++i){
        int w = wv[i].first;
        int v = wv[i].second;
        for (int j = s; j >= w; --j){
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[s];
    return 0;
}