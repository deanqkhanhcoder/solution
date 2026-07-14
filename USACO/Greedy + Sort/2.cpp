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
    #define TASK "lemonade"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a), greater<int>());
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (ans <= a[i]){
            ans ++;
        } else break;
    }
    cout << ans << endl;
    return 0;
}
