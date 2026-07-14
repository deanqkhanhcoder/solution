#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "mountains"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (pair<int, int> &p : a){
        int x, y; cin >> x >> y;
        p.first = x - y;
        p.second = x + y;
    }
    sort(all(a), [](auto A, auto B){
        if (A.first != B.first)
            return A.first < B.first;
        return A.second > B.second;
    });
    // for (int i = 0; i < n; ++i){
    //     cerr << "i : " << a[i].first << " " << a[i].second << endl; 
    // }
    // vector<pair<int, int>> segment;
    // int max_r = a[0].second;
    // int curr_l = a[0].first;
    // int in = 0;
    // for (int i = 1; i < n; ++i){
    //     if (a[i].first <= max_r){
    //         if (a[i].second <= max_r) in++;
    //         max_r = max(max_r, a[i].second); 
    //     } else {
    //         segment.push_back({curr_l, max_r});
    //         curr_l = a[i].first;
    //         max_r = a[i].second;
    //     }
    // }
    // segment.push_back({curr_l, max_r});
    // cout << n - in << endl;
    int max_r = -INF;
    int in = 0;
    for (auto [l, r] : a){
        if (r <= max_r)
            in++;
        else
            max_r = r;
    }
    cout << n - in << endl;
    return 0;
}