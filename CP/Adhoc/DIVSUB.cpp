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
    int n, P; cin >> n >> P;
    string s; cin >> s;
    ll ans = 0;
    if (P == 2 || P == 5) {
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            if (d % P == 0) {
                ans += (i + 1);
            }
        }
        cout << ans;
        return 0;
    }
    vector<int> mod(P, 0);
    mod[0] = 1;
    int pow10 = 1;
    int t = 0;
    for (int i = n - 1; i >= 0; --i){
        int d = s[i] - '0';
        t = (d * pow10 + t) % P;
        ans += mod[t];
        mod[t]++;
        pow10 = (1LL * pow10 * 10) % P; 
    }
    cout << ans;
    return 0;
}