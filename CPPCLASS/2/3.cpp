#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr ll INFLL = (ll)2e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n, m, k; cin >> n >> m >> k;
    auto check = [&](ll X){
        ll cnt = 0;
        for (int i = 1; i <= n && 1LL * i * i < X; ++i){
            ll sq = X - 1LL * i * i;
            if (sq <= 0) break;
            ll root = (int)sqrt(sq);
            root = min((ll)m, root);
            cnt += root;
        };
        return cnt >= k;
    };
    ll lo = 1, hi = INFLL;
    while (lo < hi){
        ll mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
    return 0;
}