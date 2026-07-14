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
    #define TASK "angry"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    int range = a.back() - a[0];
    int lo = 0, hi = range / 2;
    auto check = [&](int r){
        int d = r * 2;
        int idx = 0;
        int used_k = 0;
        while(idx < n){
            int next_val = a[idx] + d;
            int next_idx = upper_bound(a.begin() + idx + 1, a.end(), next_val) - a.begin();
            used_k++;
            if (used_k > k) return false;
            idx = next_idx;
        }
        return true;
    };
    while(lo < hi){
        int mid = (hi + lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
}