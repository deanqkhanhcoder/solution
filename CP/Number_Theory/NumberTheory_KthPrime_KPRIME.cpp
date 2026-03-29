#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <bitset>
using namespace std;
using ll = long long;
constexpr int MAXN = (int)1e7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, k; cin >> n >> k;
    bitset<MAXN + 1> ip;
    ip.set();
    ip[0] = ip[1] = 0;
    for (int i = 4; i <= MAXN; i += 2) ip[i] = 0;
    for (int i = 3; i * i <= MAXN; i += 2){
        if (ip[i]){
            for (ll j = i * i; j <= MAXN; j += 2 * i){
                ip[j] = 0;
            }
        }
    }
    int l = 1, r = 3;
    int cnt = 1;
    for (; r <= n; r += 2){
        if (ip[r]) cnt++;
        if (cnt == k) break;
    }
    ll ans = 0;
    for (; r <= n; ++r){
        if (!ip[r]) continue;
        while(!ip[l]){
            ans += n - r + 1;
            ++l;
        }
        ans += n - r + 1;
        ++l;
    }
    cout << ans;
    return 0;
}