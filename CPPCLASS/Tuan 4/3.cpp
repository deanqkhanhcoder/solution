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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    int n; cin >> n;
    vector<int> phi(n + 1);
    for (int i = 1; i <= n; ++i) phi[i] = i;
    for (int i = 2; i <= n; ++i){
        if (phi[i] == i){
            for (int j = i; j <= n; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        cnt[phi[i]]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        if (cnt[i] == 0) continue;
        ll contribution = cnt[i] * (cnt[i] - 1) / 2;
        ans += contribution;
    }
    cout << ans << endl;
    return 0;
}