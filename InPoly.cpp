#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using pt = pair<ll,ll>;
ll cross(const pt &a, const pt &b, const pt &c){
    ll abx = b.first - a.first;
    ll aby = b.second - a.second;
    ll acx = c.first - a.first;
    ll acy = c.second - a.second;
    return abx * acy - aby * acx;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pt> a(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    int m; cin >> m;
    while (m--){
        pt p;
        cin >> p.first >> p.second;
        if (cross(a[1], a[2], p) <= 0 || cross(a[1], a[n], p) >= 0) {
            cout << 0 << "\n";
            continue;
        }
        int l = 2, r = n;
        while (r - l > 1){
            int mid = (l + r) >> 1;
            if (cross(a[1], a[mid], p) > 0) l = mid;
            else r = mid;
        }
        ll c = cross(a[l], a[r], p);
        cout << (c >= 0 ? 1 : 0) << "\n";
    }
    return 0;
}