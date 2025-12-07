#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
<<<<<<< HEAD
 
=======

>>>>>>> fc964da59868ee8c979606f3d5960248d4dd0ed9
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
<<<<<<< HEAD
    vector<int> a(m);
    for (int &e : a) cin >> e;
    vector<char> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i){
=======
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<char> dp(m + 1, 0);
    for (int i = 1; i <= m; ++i){
>>>>>>> fc964da59868ee8c979606f3d5960248d4dd0ed9
        for (int e : a){
            if (i >= e && dp[i - e] == 0){
                dp[i] = 1;
                break;
            }
        }
    }
<<<<<<< HEAD
    cout << (dp[n] ? "Marisa" : "Reimu");
=======
    cout << (dp[m] ? "Marisa" : "Reimu");
>>>>>>> fc964da59868ee8c979606f3d5960248d4dd0ed9
    return 0;
}