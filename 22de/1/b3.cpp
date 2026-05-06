#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int MAXD = 150;
constexpr ll MAXA = (ll)1e14;
bitset<MAXD> ip;
ll dp[16][MAXD][2];
int vis[16][MAXD][2];
string s;
int len;
int curtime = 0;
ll dfs(int pos, int sumd, int smaller){
    if (pos == len){
        return ip[sumd];
    }
    if (curtime == vis[pos][sumd][smaller]) return dp[pos][sumd][smaller];
    ll res = 0;
    vis[pos][sumd][smaller] = curtime;
    int limit = (smaller ? 9 : s[pos] - '0');
    for (int d = 0; d <= limit; ++d){
        bool nsmaller = (smaller || (d < limit));
        int nsumd = sumd + d;
        res += dfs(pos + 1, nsumd, nsmaller);
    }
    return dp[pos][sumd][smaller] = res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int T; cin >> T;
    ip.set();
    ip[0] = ip[1] = 0;
    for (int i = 4; i < MAXD; i += 2) ip[i] = 0;
    for (int i = 3; i * i < MAXD; i += 2){
        if (ip[i]){
            for (int j = i * i; j < MAXD; j += i * 2){
                ip[j] = 0;
            }
        }
    }    
    auto sumd = [](ll x){
        int res = 0;
        while (x){
            res += x % 10;
            x /= 10;
        }
        return res;
    };
    vector<ll> perfect;
    perfect.reserve(1e6);
    for (int i = 1; 1LL * i * i <= MAXA; ++i){
        ll x = 1LL * i * i;
        if (ip[sumd(x)]) perfect.push_back(x);
    }
    auto query = [&](ll x) -> ll{
        curtime++;
        if (x <= 1) return 0;
        s = to_string(x);
        len = s.length();
        ll ans = dfs(0, 0, 0);
        auto it = upper_bound(all(perfect), x);
        ll leftover = it - perfect.begin();
        ans -= leftover;
        return ans;
    };
    auto querylr = [&](ll l, ll r) -> ll{
        return query(r) - query(l - 1);
    };
    while (T--){
        ll a, b; cin >> a >> b;
        cout << querylr(a, b) << endl;
    }
    return 0;
}