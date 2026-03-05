#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;
int n, p;
vector<int> a;

bool check(int mid){
    vector<int> dp(n + 1, 0);
    for (int k = 3; k <= n; ++k){
        dp[k] = dp[k - 1];
        for (int j = k - 1; j >= 2; --j){
            if (abs(a[k] - a[j]) > mid) continue;
            if (dp[k] >= dp[j - 1] + 1) break;
            for (int i = j - 1; i >= 1; --i){
                int q1 = max(a[i], max(a[j], a[k]));
                int q2 = min(a[i], min(a[j], a[k]));
                if (q1 - q2 <= mid){
                    dp[k] = max(dp[k], dp[i - 1] + 1);
                    break;
                }
            }
            if (dp[k] > dp[k-1]) break;
        }
        if (dp[k] >= p) return true;
    }   
    return dp[n] >= p;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    cin >> n >> p;
    a.resize(n + 1);
    int maxest = INT_MIN;
    int minest = INT_MAX;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        maxest = max(maxest, a[i]);
        minest = min(minest, a[i]);
    }
    if (3 * p == n) {
        int res = INT_MIN;
        for (int i = 1; i <= n; i += 3) {
            int m1 = max(a[i], max(a[i + 1], a[i + 2]));
            int m2 = min(a[i], min(a[i + 1], a[i + 2]));
            res = max(res, m1 - m2);
        }
        cout << res << '\n';
        return 0;
    }
    int l = 0;
    int r = maxest - minest;
    while (l < r){
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}