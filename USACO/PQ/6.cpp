// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("inline")
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #define endl '\n'
// #define sz(x) (int)x.size()
// #define all(x) x.begin(), x.end()
// using namespace std;
// using ll = long long;
// constexpr int INF = (int)1e9;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // #define TASK "haybales"
//     // freopen(TASK".in", "r", stdin);
//     // freopen(TASK".out", "w", stdout);
//     int t; cin >> t;
//     while (t--){
//         int n; cin >> n;
//         vector<pair<int, int>> a(n);
//         for (pair<int, int> &p : a) cin >> p.first >> p.second;
//         sort(all(a));
//         for (int i = 1; i < n; ++i){
//             if (a[i].first == a[i - 1].first){
//                 a[i].first++;
//                 if (a[i].first > a[i].second) {
//                     cout << "NO" << endl;
//                     goto end;
//                 }
//             } else if (a[i].first < a[i - 1].first){
//                 a[i].first += 2;
//                 if (a[i].first > a[i].second){
//                     cout << "NO" << endl;
//                     goto end;
//                 }
//             }
//         }
//         cout << "YES" << endl;
//         end:;
//     }
//     return 0;
// }
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for (pair<int, int> &p : a) cin >> p.first >> p.second;
        sort(all(a));
        int i = 0;
        int curr = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        while(i < n || !pq.empty()){
            if (pq.empty()){
                curr = a[i].first;
            }
            while (i < n && a[i].first <= curr){
                pq.push(a[i].second);
                i++;
            }
            int r = pq.top();
            pq.pop();
            if (r < curr){
                cout << "NO" << endl;
                goto end;
            }
            curr++;
        }
        cout << "YES" << endl;
        end:;
    }
    return 0;
}