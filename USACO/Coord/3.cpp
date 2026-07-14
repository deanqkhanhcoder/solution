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
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (pair<int, int> &p : a) cin >> p.first >> p.second;
    sort(all(a));
    vector<int> in(n), out(n);
    for (int i = 0; i < n; ++i) in[i] = a[i].first;
    for (int i = 0; i < n; ++i) out[i] = a[i].second;
    sort(all(out));
    in.erase(unique(all(in)), in.end());
    out.erase(unique(all(out)), out.end());
    vector<pair<int, int>> segment;
    int max_r = a[0].second;
    int curr_l = a[0].first;
    bool overlap = false;
    for (int i = 1; i < n; ++i){
        if (a[i].first <= max_r){
            if (a[i].second <= max_r) overlap = true;
            max_r = max(max_r, a[i].second);
        }
        else{
            segment.push_back({curr_l, max_r});
            curr_l = a[i].first;
            max_r = a[i].second;
        }
    }
    segment.push_back({curr_l, max_r});
    int m = (int)segment.size();
    ll total = 0;
    for (int i = 0; i < m; ++i) total += segment[i].second - segment[i].first;
    if (overlap){
        cout << total << endl;
        return 0;
    } else {
        auto get = [&](int a, int b){
            auto it_l = lower_bound(all(out), b);
            int l = a;
            if (it_l != out.begin()){
                it_l--;
                l = max(l, *it_l + 1);
            }
            auto it_r = upper_bound(all(in), a);
            int r = b;
            if (it_r != in.end()){
                r = min(r, *it_r - 1);
            }
            if (l > r) return 0;
            return r - l;
        };
        ll ans = 0;
        for (int i = 0; i < n; ++i){
            pair<int, int> this_block = a[i];
            ans = max(ans, total - get(this_block.first, this_block.second)); 
        }
        cout << ans << endl;
        cerr << total - get(3, 7) << endl;
    }
}