#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> next(n + 1);
    vector<int> st;
    for (int i = 0; i < n; ++i){
        while (!st.empty() && a[st.back()] < a[i]){
            next[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while (!st.empty()) {
        next[st.back()] = n;
        st.pop_back();
    }
    next[n] = n;
    const int LOG = __lg(n);
    vector<vector<int>> up(n + 1, vector<int>(LOG + 1));
    for (int i = 0; i <= n; ++i) up[i][0] = next[i];
    for (int k = 1; k <= LOG; ++k){
        for (int i = 0; i <= n; ++i){
            up[i][k] = up[up[i][k - 1]][k - 1];
        }
    }
    while (q--){
        int l, r; cin >> l >> r;
        l--; r--;
        int ans = 1;
        int u = l;
        for (int k = LOG; k >= 0; k--){
            if (up[u][k] <= r){
                ans += (1 << k);
                u = up[u][k];
            }
        }
        cout << ans << endl;
    }
    return 0;
}