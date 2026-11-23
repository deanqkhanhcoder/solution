#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
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
    #define TASK "LPERM"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n, k; cin >> n >> k;
    const int OFFSET = 1000000;
    const int MAXA = 2000105;
    vector<int> cnt(MAXA);
    // cnt[0 + OFFSET] = 1;
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        for (int j = x + 1; j <= x + k; ++j){
            ans += cnt[j + OFFSET];
        }
        cnt[x + OFFSET]++;
    }
    cout << ans << endl;
    return 0;
}