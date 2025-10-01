#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<bool> dp(k + 1, false);
    for (int i = 1; i <= k; ++i){
        for (int e : a){
            if (i - e < 0) continue;
            if (!dp[i - e]){
                 dp[i] = true;
                 break;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second");
}
