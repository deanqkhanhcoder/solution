// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("inline")
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// using ll = long long;
// constexpr int MAXN = 2000;
// struct student{
//     int sum;
//     int i;
//     int j;
//     bool operator < (const student &other) const{
//         if (sum != other.sum) return sum < other.sum;
//         if (i != other.i) return i < other.i;
//         return j > other.j;
//     }
// };
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     freopen("PAIR.INP", "r", stdin);
//     freopen("PAIR.OUT", "w", stdout);
//     int n, d; cin >> n >> d;
//     vector<int> a(n);
//     for (int &e : a) cin >> e;
//     vector<student> pair;
//     for (int i = 0; i < n; ++i){
//         for (int j = i + 1; j < n; ++j){
//             pair.push_back({a[i] + a[j], i, j});
//         }
//     }
//     int m = pair.size();
//     sort(pair.begin(), pair.end());
//     vector<int> vis(MAXN + 1, 0);
//     int version = 0;
//     int r = 0;
//     int res = 0;
//     for (int l = 0; l < m;){
//         int lsum = pair[l].sum;
//         int nextl = r;
//         while (r < m && pair[r].sum <= lsum + d){
//             if (pair[l].sum == pair[r].sum) nextl = r;
//             r++;
//         }
//         version++;
//         int ans = 0;
//         for (int k = l; k < r; ++k){
//             int i = pair[k].i;
//             int j = pair[k].j;
//             if (vis[i] != version && vis[j] != version){
//                 ans++;
//                 vis[i] = version;
//                 vis[j] = version;
//             }
//         }
//         res = max(res, ans);
//         l = nextl + 1;
//     }
//     cout << res;
//     return 0;
// }

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("PAIR.INP", "r", stdin);
    freopen("PAIR.OUT", "w", stdout);
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(a.begin(), a.end());
    vector<int> sums;
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            sums.push_back(a[i] + a[j]);
        }
    }
    sort(sums.begin(),sums.end());
    int m = sums.size();
    vector<pair<int, int>> freq;
    for (int l = 0; l < m;){
        int r = l;
        int cnt = 0;
        while (r < m && sums[l] == sums[r]){
            r++;
            cnt++;
        }
        freq.push_back({sums[l], r - l});
        l = r;
    }
    int k = freq.size();
    vector<pair<int, int>> check;
    for (int i = 0; i < k; ++i){
        int s = freq[i].first;
        int cnt1 = freq[i].second;
        int cnt2 = 0;
        if (d == 1){
            if (i + 1 < k && freq[i + 1].first <= s + 1){
                cnt2 = freq[i + 1].second;
            }
        }
        check.push_back({s, cnt1 + cnt2});
        if (d == 1){
            if (s != 1 && (i == 0 || freq[i - 1].first != s - 1)){
                check.push_back({s - 1, cnt1});
            }
        }
    }
    sort(check.begin(), check.end(), [](auto &a, auto &b){
        return a.second > b.second;
    });
    int ans = 0;
    for (auto &p : check){
        if (ans >= p.second) break;
        int i = 0, j = n - 1;
        int S = p.first;
        int cnt = 0;
        while (i < j){
            int cur = a[i] + a[j];
            if (cur < S){
                i++;
            } else if (cur > S + d){
                j--;
            } else {
                cnt++;
                i++;
                j--;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}