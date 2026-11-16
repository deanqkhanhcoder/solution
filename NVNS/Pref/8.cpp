#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr ll INFLL = (ll)1e18;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        unordered_map<int, int> cnt;
        cnt.max_load_factor(0.7);
        cnt[a[0]] = 1;
        ll ans = 0;
        for (int k = 1; k < n - 1; ++k){
            for (int j = k + 1; j < n; ++j){
                ll target = 2LL * a[k] - a[j];
                if (llabs(target) > INF) continue;
                auto it = cnt.find(target);
                if (it != cnt.end()) {
                    ans += it->second;
                }
            }
            cnt[a[k]]++;
        }
        cout << ans << endl;
    }
    return 0;
}