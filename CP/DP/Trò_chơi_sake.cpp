#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int &e : a) cin >> e;
    vector<char> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        for (int e : a){
            if (i >= e && dp[i - e] == 0){
                dp[i] = 1;
                break;
            }
        }
    }
    cout << (dp[n] ? "Marisa" : "Reimu");
    return 0;
}