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
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "loan"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    // code here
    ll n, k, m; cin >> n >> k >> m;
    auto check = [&](ll X) -> bool {
        ll cur_n = n;
        ll cur_k = k;
        while (cur_n > 0 && cur_k > 0) {
            ll Y = cur_n / X;
            if (Y <= m) {
                return cur_k >= (cur_n + m - 1) / m;
            }
            ll days = (cur_n % X) / Y + 1;
            days = min(days, cur_k);
            cur_n -= days * Y;
            cur_k -= days;
        }
        return cur_n <= 0;
    };
    ll lo = 1, hi = n / 2;
    while (lo < hi){
        ll mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo;
}