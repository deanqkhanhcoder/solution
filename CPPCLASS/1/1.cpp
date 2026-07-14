#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define endl '\n'
#define sz(x) (int)x.size()
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
    vector<int> a(n);
    for (int &e : a) cin >> e;
    unordered_map<int, int> mp;
    mp.reserve(2 * n);
    mp.max_load_factor(0.7);
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        for (int power = 0; power <= 31; power++){
            ll target = (1LL << power) - a[i];
            if (target < 0 || target > INF) continue;
            auto it = mp.find(target);
            if (it == mp.end()) continue;
            ans += it->second;
        }
        mp[a[i]]++;
    }
    cout << ans << endl;
    return 0;
}