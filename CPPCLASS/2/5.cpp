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
constexpr ll INFLL = (ll)1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &p : a){
        cin >> p.first >> p.second;
        p.second += p.first;
    }
    sort(all(a));
    // int start = a[i].first;
    // auto check = [&](int X){
    //     int cnt = 1;
    //     int pos = start;
    //     for (int i = 0; i < n; ++i){
    //         if (pos + X <= a[i].second){
    //             cnt++;
    //             if (cnt >= n) return true;
    //             pos += X;
    //         }
    //     }
    // }
    auto check = [&](int X){
        ll pos = -INFLL;
        for (auto [l, r] : a){
            pos = max((ll)l, pos + X);
            if (pos > r) return false;
        }
        return true;
    };
    int lo = 1, hi = 2 * INF;
    while (lo < hi){
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
    return 0;
}