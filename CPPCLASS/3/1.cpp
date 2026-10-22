#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    ll n; cin >> n;
    string bits;
    ll dp[35][2][2];
    if (n == 0){
        cout << 1 << endl;
        return 0;
    }
    ll tmp = n;
    while (tmp > 0){
        bits += (tmp % 2 == 1 ? '1' : '0');
        tmp /= 2;
    }
    reverse(all(bits));
    int m = sz(bits);
    auto dfs = [&](auto &&self, int pos, bool smallerA, bool smallerB) -> ll {
        if (pos == m){
            return 1;
        }
        ll &res = dp[pos][smallerA][smallerB];
        if (res != -1) return res;
        int limitA = (smallerA ? 1 : bits[pos] - '0');
        int limitB = (smallerB ? 1 : bits[pos] - '0');
        res = 0;
        for (int a = 0; a <= limitA; ++a){
            for (int b = 0; b <= limitB; ++b){
                if (a == 1 && b == 1) continue;
                bool nsmallerA = smallerA || (a < limitA);
                bool nsmallerB = smallerB || (b < limitB);
                res += self(self, pos + 1, nsmallerA, nsmallerB);
            }
        }
        return res;
    };
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(dfs, 0, 0, 0);
    cout << ans << endl;
    return 0;
}