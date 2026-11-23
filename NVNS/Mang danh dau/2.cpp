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
    int n; cin >> n;
    const int MAXA = 1000005;
    vector<int> pref(MAXA);
    int minA = MAXA, maxA = 0;
    ll sumA = 0;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        pref[x]++;
        minA = min(minA, x);
        maxA = max(maxA, x);
        sumA += x;
    }
    for (int i = 1; i <= maxA; ++i){
        pref[i] += pref[i - 1];
    }
    ll ans = sumA + n;
    for (int k = 1; k <= minA; ++k){
        ll res = 0;
        for (int q = 0; q * (k + 1) <= maxA; ++q){
            int L = q * (k + 1);
            int R = min(maxA, (q + 1) * (k + 1) - 1);
            if (q < k){
                int invaildR = min(maxA, (q + 1) * k - 1);
                if (L <= invaildR){
                    int cnt = pref[invaildR] - (L > 0 ? pref[L - 1] : 0);
                    if (cnt) goto end;
                }
            }
            int cnt = pref[R] - (L > 0 ? pref[L - 1] : 0);
            res += 1LL * cnt * (q + 1);
        }
        ans = min(ans, res);
        end:;
    }
    cout << ans << endl;
    return 0;
}