#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    // code here
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for (int &e : a) cin >> e;
        for (int &e : b) cin >> e;
        int curr = a[0];
        int maxb = b[0];
        int ans = curr + (k - 1) * maxb;
        for (int i = 1; i < min(n, k); ++i){
            curr += a[i];
            maxb = max(maxb, b[i]);
            int total = curr + (k - i - 1) * maxb;
            ans = max(ans, total);
        }
        cout << ans << endl;
    }
    return 0;
}