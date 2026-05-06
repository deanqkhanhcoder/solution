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
constexpr int LIMIT = (int)9e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    ll n; cin >> n;
    int lo = 0, hi = LIMIT;
    while (lo < hi){
        int mid = (hi + lo + 1) / 2;
        auto check = [&](int mid){
            ll f = (1LL * 3 * mid * (mid + 3)) / 2;
            return f <= n;
        };
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo;
}