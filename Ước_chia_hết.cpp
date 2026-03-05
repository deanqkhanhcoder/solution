#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
constexpr int LIMIT = (int)1e7;
constexpr ll LIMITPR = (ll)1e12;
ll n, a, b, c;
vector<int> ip(LIMIT + 1, 0);
vector<int> pr;
bool ispr(ll n){
    for (int i = LIMIT + 1; i * i <= n; i += 6){
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
ll lcm(ll x, ll y){
    ll g = __gcd(x, y);
    ll overflow = n / y;
    if (x / g > overflow){
        return n + 1;
    }
    return (x / g) * y;
}

ll solve(ll N, ll l){
    if (N % l != 0) return 0;
    N /= l;
    ll d = 1;
    if (N <= LIMIT){
        while (N > 1){
            int spf = ip[N];
            int e = 0;
            while (N % spf == 0) N /= spf, e++;
            d *= (e + 1);
        }
    }
    else {
        for (int &p : pr){
            if (p * p > N) break;
            int e = 0;
            while (N % p == 0) N /= p, e++;
            d *= (e + 1);
        }
        if (N > 1){
            if (N <= LIMIT){
                while (N > 1){
                    int spf = ip[N];
                    int e = 0;
                    while (N % spf == 0) N /= spf, e++;
                    d *= (e + 1);
                }
            } else {
                ll sq = sqrt(N);
                if (sq * sq == N) d *= 3;
                else {
                    if (ispr(N)) d *= 2;
                    else d *= 4;
                }
            }
        }
    }
    return d;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    cin >> n >> a >> b >> c;
    for (int i = 2; i <= LIMIT; ++i){
        if (ip[i] == 0){
            ip[i] = i;
            pr.push_back(i);    
        }
        for (int &p : pr){
            if (1LL * i * p > LIMIT) break;
            ip[i * p] = p;
            if (ip[i] == p) break;
        }
    }
    ll lab = lcm(a, b);
    ll lbc = lcm(b, c);
    ll lca = lcm(c, a);
    ll lnabc = lcm(c, lab);
    ll ans = solve(n, lab) + solve(n, lbc) + solve(n, lca) - 2*solve(n, lnabc);
    cout << ans;
}