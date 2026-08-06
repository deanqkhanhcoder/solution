#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
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
    auto bin_pow = [&](int a, int b, int m){
        a %= m;
        int res = 1;
        while (b){
            if (b & 1) res = (1LL * res * a) % m;
            a = (1LL * a * a) % m;
            b >>= 1;
        }
        return res;
    };
    cout << bin_pow(2, n, MOD) << endl;
    return 0;
}