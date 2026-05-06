#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int n; string s; 
    cin >> n >> s;
    vector<int> pos;
    pos.reserve(n);
    for (int i = 0; i < n; ++i){
        if (s[i] == '1') pos.push_back(i + 1);
    }
    int sz = (int)pos.size();
    if (sz == 0){
        cout << n - 1;
        return 0;
    } 
    if (sz == 1){
        int ans = min(pos[0] - 1, n - pos[0]);
        ans = max(ans, (pos[0] - 1) / 2);
        ans = max(ans, (n - pos[0]) / 2);
        cout << ans;
        return 0;
    }
    if (sz == 2){
        int ans = min(pos[1] - pos[0], min(pos[0] - 1, n - pos[1]));
        ans = max(ans, min(pos[0] - 1, (pos[1] - pos[0]) / 2));
        ans = max(ans, min(n - pos[1], (pos[1] - pos[0]) / 2));
        ans = max(ans, (pos[1] - pos[0]) / 3);
        cout << ans;
        return 0;
    }
    vector<int> diff(sz - 1);
    int diffs = sz - 1;
    for (int i = 1; i < sz; ++i){
        diff[i - 1] = pos[i] - pos[i - 1];
    }
    sort(all(diff));
    int ans = min(diff.front(), min(pos[0] - 1, n - pos.back()));
    int largesecond = diff[diffs - 2];
    ans = max(ans, min(diff.front(), min(diff.back() / 2, largesecond / 2)));
    ans = max(ans, min(diff.front(), diff.back() / 3));
    ans = max(ans, min(diff.front(), min(pos[0] - 1, diff.back() / 2)));
    ans = max(ans, min(diff.front(), min(n - pos.back(), diff.back() / 2)));
    cout << ans;
    return 0;
}
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("inline")
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_set>
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// using namespace std;
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     freopen("socdist1.in", "r", stdin);
//     freopen("socdist1.out", "w", stdout);
//     int n; string s; 
//     cin >> n >> s;
//     vector<int> pos;
//     pos.reserve(n);
//     for (int i = 0; i < n; ++i){
//         if (s[i] == '1') pos.push_back(i + 1);
//     }
//     int sz = (int)pos.size();
//     if (sz == 0){
//         cout << n - 1;
//         return 0;
//     } 
//     if (sz == 1){
//         int ans = min(pos[0] - 1, n - pos[0]);
//         ans = max(ans, (pos[0] - 1) / 2);
//         ans = max(ans, (n - pos[0]) / 2);
//         cout << ans;
//         return 0;
//     }
//     vector<int> diff(sz - 1);
//     for (int i = 1; i < sz; ++i){
//         diff[i - 1] = pos[i] - pos[i - 1];
//     }
//     sort(all(diff));
//     int ans = min(pos[0] - 1, n - pos.back());
//     for (int i = 0; i < sz - 1; ++i){
//         ans = max(ans, diff[i] / 2);
//     }
//     cout << ans;
//     return 0;
// }