#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        ll ans = 0;
        for (int i = 1; i < n; ++i){
            if (a[i] < a[i + 1]){
                int diff = a[i + 1] - a[i];
                if (i + 2 > n){
                    ans = -1;
                    break;
                }
                a[i + 1] -= diff;
                a[i + 2] -= diff;
                if (a[i + 2] < 0) {
                    ans = -1;
                    break;
                }
                ans += 1LL * diff * 2;
            } else if (a[i] > a[i + 1]){
                if (i & 1){
                    ans = -1;
                    break;
                }
                int diff = a[i] - a[i + 1];
                ans += 1LL * diff * i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}