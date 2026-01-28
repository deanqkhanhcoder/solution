#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> sub;
            for (int k = i; k <= j; k++) {
                sub.push_back(a[k]);
            }
            sort(sub.begin(), sub.end());
            int k = sub.size();
            int median;
            if (k % 2 != 0) { // k lẻ
                median = sub[(k + 1) / 2 - 1];
            } else { // k chẵn
                median = sub[k / 2 - 1];
            }
            if (median == M) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}