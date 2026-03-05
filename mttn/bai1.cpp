#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

/* ===================== GLOBAL ===================== */

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};

/* ===================== MAIN ===================== */

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    // int T = 1;
    // // cin >> T; // turn on if have many test
    // while (T--) {
        
        
    // }
    // // code here
    ll n; cin >> n;
    ll ans = -1;
    for (ll i = n - 1; i * i >= n; --i){
        if (n % i == 0) ans = i;
    }
    cout << ans;
    return 0;
}