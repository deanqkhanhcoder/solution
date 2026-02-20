#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, S; cin >> n >> S;
    vector<pair<int, int>> a(n);
    for (pair<int, int> &p : a) cin >> p.first >> p.second;
    vector<int> dp(S + 1, 0);
    for (auto &p : a){
        int w = p.first;
        int v = p.second;
        for (int i = S; i >= w; i--){
            dp[i] = max(dp[i], dp[i - w] + v);
        }
    }
    cout << dp[S];
    return 0;
}