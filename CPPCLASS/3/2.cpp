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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; ll S; cin >> n >> S;
    vector<pair<ll, ll>> exist;  
    vector<pair<ll, ll>> extended; 
    ll curW = 0, curV = 0;
    for (int i = 0; i < n; ++i) {
        ll w, v; int c;
        cin >> w >> v >> c;
        if (c == 1) {
            exist.push_back({w, v});
            curW += w;
            curV += v;
        } else {
            extended.push_back({w, v});
        }
    }
    ll ans = curV;
    if (!extended.empty()) {
        sort(all(extended));
        vector<pair<ll, ll>> alive;
        for (auto [w, v] : extended) {
            if (!alive.empty() && alive.back().first == w) {
                alive.back().second = max(alive.back().second, v);
            } else {
                alive.push_back({w, v});
            }
        }
        for (size_t i = 1; i < alive.size(); ++i) {
            alive[i].second = max(alive[i].second, alive[i - 1].second);
        }
        if (S - curW >= 0) {
            ll rem = S - curW;
            auto it = upper_bound(all(alive), make_pair(rem, (ll)2e18));
            if (it != alive.begin()) {
                --it;
                ans = max(ans, curV + it->second);
            }
        }
        for (auto [w, v] : exist) {
            ll target = S - (curW - w);
            if (target < 0) continue;
            auto it = upper_bound(all(alive), make_pair(target, (ll)2e18));
            if (it != alive.begin()) {
                --it;
                ans = max(ans, curV - v + it->second);
            }
        }
    }
    cout << ans << endl;
    return 0;
}