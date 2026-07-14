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
    int x, n; cin >> x >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    int ans = 0;
    for (int i = n - 1; i >= 1; --i){
        ans += x;
        x -= a[i];
    }
    cout << ans << endl;
    return 0;
}