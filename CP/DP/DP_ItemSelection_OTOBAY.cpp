#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr ll INF = (ll)1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    int maxest = 0;
    ll sum = 0;
    for (int &e : a){
        cin >> e;
        maxest = max(maxest , e);
        sum += e;
    }
    ll ans = 0;
    if (k == 0){
        for (int i = 0; i < n; ++i){
            ans += maxest - a[i];
        }
    } else if (k == -1){
        int i;
        for (i = 1; i < n; ++i){
            if (a[i] > a[0]){
                break;
            }
            ans += a[0] - a[i];
        }
        for (;i < n; ++i){
            ans += maxest - a[i];
        }
    } else {
        ans = (ll)maxest * n;
        vector<int> prmax(n + 1, 0);
        vector<int> sufmax(n + 2, 0);
        for (int i = 1; i <= n; ++i) prmax[i] = max(prmax[i - 1], a[i - 1]);
        for (int i = n; i >= 1; --i) sufmax[i] = max(sufmax[i + 1], a[i - 1]);
        for (int i = 2; i <= n; ++i){
            int sum1 = prmax[i - 1];
            int sum2 = max(sum1, sufmax[i]);
            ll cost = (ll)sum1 * (i - 1) + (ll)sum2 * (n - i + 1) - sum;
            ans = min(ans, cost);
        }
    }
    cout << ans;
    return 0;
}