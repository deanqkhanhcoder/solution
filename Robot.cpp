#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using ll = long long;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a, b; cin >> a >> b;
    vector<pair<int,int>> d(n);
    for (pair<int,int> &q : d) cin >> q.first >> q.second;
    int s1 = n / 2;
    int s2 = n - s1;
    vector<pair<ll,ll>> sub1;
    sub1.reserve(1 << s1);
    for (int mask = 0; mask < 1<<s1; ++mask){
        ll d1 = 0;
        ll d2 = 0;
        for (int i = 0; i < s1; ++i){
            if (mask & (1<<i)){
                d1 += d[i].first;
                d2 += d[i].second;
            }
        }
        sub1.push_back({d1,d2});
    }
    map<pair<ll,ll>,int> sub2;
    for (int mask = 0; mask < 1<<s2; ++mask){
        ll d1 = 0;
        ll d2 = 0;
        for (int i = 0; i < s2; ++i){
            if (mask & (1<<i)){
                d1 += d[i + s1].first;
                d2 += d[i + s1].second;
            }
        }
        sub2[{d1,d2}]++;
    }
    ll ans = 0;
    for (auto [x, y]: sub1){
        pair<ll, ll> t = {a - x, b - y};
        ans += sub2[t];
    }
    cout << ans;
    return 0;
}