#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n, target; cin >> n >> target;
    vector<int> a(n);
    iota(all(a), 1);
    // reverse(all(a));
    // int curr_g = a[0];
    // ll ans = 0;
    // for (int i = 0; i < n; ++i){
    //     curr_g = __gcd(curr_g, a[i]);
    //     if (curr_g == g){
    //         ll contibution = 1LL * (i + 1) * (i + 2) / 2;
    //         ans += contibution;
    //     } 
    //     if (curr_g < g) break;
    // }
    // cout << ans << endl;
    // return 0;
    vector<pair<int, ll>> cur, prev;
    ll ans = 0;
    for (int x : a){
        cur.clear();
        cur.push_back({x, 1});
        for (auto [g, cnt] : prev){
            int ng = __gcd(g, x);
            if (cur.back().first == ng){
                cur.back().second += cnt;
            } else {
                cur.push_back({ng, cnt});
            }
        }
        for (auto [g, cnt] : cur){
            if (g == target) ans += cnt;
        }
        prev.swap(cur);
    }
    cout << ans << endl;
    return 0;
}