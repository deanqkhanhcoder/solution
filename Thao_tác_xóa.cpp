#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll NEG_INF = -1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<ll>> keep(n + 1, vector<ll>(k + 1, NEG_INF));
    vector<vector<ll>> rem(n + 1, vector<ll>(k + 1, NEG_INF));
    keep[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            keep[i][j] = max(keep[i][j], keep[i - 1][j] + a[i]);
            keep[i][j] = max(keep[i][j], rem[i - 1][j]);
            if (j > 0) {
                rem[i][j] = max(rem[i][j], keep[i - 1][j - 1]);
                rem[i][j] = max(rem[i][j], rem[i - 1][j]);
            }
        }
    }

    ll ans = NEG_INF;
    for (ll e : keep[n]) ans = max(ans, e);
    cout << ans;
    return 0;
}
