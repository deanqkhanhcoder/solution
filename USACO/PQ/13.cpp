#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &e : a) cin >> e;
    sort(all(a));
    ll ans = 0;
    auto power = [&](ll a, ll b){
        a %= MOD;
        ll res = 1; 
        while (b){
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1; 
        }
        return res;
    };
    int m = n;
    for (int step = 0; step < n - 1; ++step){    
        ll base = a[0];
        ll contribution = ((base % MOD) * power(2, m - 1)) % MOD;
        ans = (ans + contribution) % MOD;
        for (int i = 0; i < m; ++i) a[i] -= base;
        using node = pair<ll, pair<int, int>>;
        priority_queue<node, vector<node>, greater<node>> pq;
        for (int i = 0; i < m - 1; ++i) pq.push({a[i] + a[i + 1], {i, i + 1}});
        vector<ll> b;
        b.reserve(m - 1);
        for (int i = 0; i < m - 1; ++i){
            auto [sum, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();
            b.push_back(sum);
            if (y + 1 < m){
                pq.push({a[x] + a[y + 1], {x, y + 1}});
            }
        }
        a = b;
        m--;
    }
    ans = (ans + a[0] % MOD) % MOD;
    cout << ans << endl;
}