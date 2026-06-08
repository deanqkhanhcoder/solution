#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr ll INF = (ll)1e18 + 1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    // code here
    ll n; cin >> n;
    int k; cin >> k;
    const int LIMIT = (int)round((ll)cbrt(n)) + 1000;
    vector<bool> ip(LIMIT + 1, true);
    vector<int> pr;
    pr.reserve(LIMIT);
    ip[0] = ip[1] = false;
    for (int i = 2; i <= LIMIT; ++i){
        if (ip[i]){
            pr.push_back(i);
        }
        for (int p : pr){
            if (1LL * i * p > LIMIT) break;
            ip[i * p] = false;
            if (i % p == 0) break;
        }
    }
    vector<tuple<int,int,int>> s;
    for (int a = 2; a <= k; ++a){
        if (k % a) continue;
        for (int b = 2; b <= k; ++b){
            if ((k / a) % b) continue;
            int c = k / a / b;
            if (c < 2) continue;
            s.push_back({a,b,c});
        }
    }
    auto poww = [&](ll a, int b) -> ll{
        ll res = 1;
        while(b){
            if (b & 1) {
                if (res > n / a){
                    return INF;
                }
                res *= a;
            }
            b >>= 1;
            if (b == 0) break;
            if (a > n / a){
                return INF;
            }
            a *= a;
        }
        return res;
    };
    ll ans = 0;
    for (auto [a, b, c] : s){
        int e1 = a - 1;
        int e2 = b - 1;
        int e3 = c - 1;
        for (int i = 0; i < (int)pr.size() - 2; ++i){
            int p1 = pr[i];
            int p2 = pr[i + 1];
            int p3 = pr[i + 2];
            ll power1 = poww((ll)p1, e1);
            ll power2 = poww((ll)p2, e2);
            ll power3 = poww((ll)p3, e3);
            if (power1 > n || power2 > n || power3 > n) break;
            if (power1 > n / power2) break;
            ll power12 = power1 * power2;
            if (power12 > n / power3) break;
            ll res = power12 * power3;
            ans = max(ans, res);
        }
    }
    cout << ans;
}