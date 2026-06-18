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
    #define TASK "convention"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n, M, C; cin >> n >> M >> C;
    vector<int> a(n);
    int mn = INF;
    int mx = 0;
    for(int &e : a){
        cin >> e;
        mn = min(mn, e);
        mx = max(mx, e);
    }
    sort(all(a));
    auto check = [&](int diff){
        int used_m = 0;
        int r = 0;
        for (int l = 0; l < n;){
            while(r < n && r - l + 1 <= C && a[r] - a[l] <= diff) r++;
            used_m++;
            // cerr << "used_m = " << used_m << endl;
            if (used_m > M) return false;
            l = r;
        }
        return true;
    };
    // cerr << check(0) << endl;
    int lo = 0, hi = mx - mn;
    // cerr << "hi = " << hi << endl;
    while (lo < hi){
        int mid = (hi + lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    } 
    cout << lo;
    return 0;
}