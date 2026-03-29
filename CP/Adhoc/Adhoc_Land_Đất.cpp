#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr ll INF = (ll)1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y, z; cin >> n >> x >> y >> z;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    int OFFSET = n * 10;
    int SIZE = 2 * OFFSET;
    vector<ll> dp1(SIZE + 1, INF);
    vector<ll> dp2(SIZE + 1, INF);
    dp1[OFFSET] = 0;
    for (int i = 0; i < n; ++i){
        fill(dp2.begin(), dp2.end(), INF);
        int dif = a[i] - b[i];
        for (int k = 0; k <= SIZE; ++k){
            if (dp1[k] == INF) continue;
            int cb = k - OFFSET;
            ll cost = llabs(cb) * z;
            int nb = cb + dif;
            int nk = nb + OFFSET;
            if (nk >= 0 && nk <= SIZE){
                dp2[nk] = min(dp2[nk], dp1[k] + cost);
            }
        }
        for (int k = 1; k <= SIZE; ++k){
            if (dp2[k - 1] != INF){
                dp2[k] = min(dp2[k], dp2[k - 1] + x);
            }
        }
        for (int k = SIZE - 1; k >= 0; --k){
            if (dp2[k + 1] != INF){
                dp2[k] = min(dp2[k], dp2[k + 1] + y);
            }
        }
        dp1 = dp2;
    }
    cout << dp2[OFFSET];
    return 0;
}