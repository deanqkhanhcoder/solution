#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, f; cin >> n >> f;
    vector<pair<int, int>> days(n);
    vector<int> extra;
    extra.reserve(n);
    ll ans = 0;
    for (auto &p : days){
        cin >> p.first >> p.second;
        ans += min(p.first, p.second);
        extra.push_back(min(2 * p.first, p.second) - min(p.first, p.second));
    }
    sort(all(extra), greater<int>());
    for (int i = 0; i < f; ++i){
        ans += extra[i];
    }
    cout << ans << endl;
    return 0;
}