#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr ll INFLL = (ll)1e18;
constexpr int MOD = (int)1e9 + 7;
struct SparseTable{
    int n;
    vector<int> lg;
    vector<vector<ll>> st;
    SparseTable(vector<ll> &a){
        n = (int)a.size();
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
        int LOG = lg[n];
        st.assign(LOG + 1, vector<ll>(n));
        st[0] = a;
        for (int k = 1; k <= LOG; ++k){
            for (int i = 0; i + (1 << k) <= n; ++i){
                st[k][i] = min(
                    st[k - 1][i], 
                    st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }
    ll query(int l, int r){
        l = max(0, l);
        int len = r - l + 1;
        int k = lg[len];
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, L, R; cin >> n >> L >> R;
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        pref[i] = pref[i - 1] + x;
    }
    SparseTable st(pref);
    ll ans = -INFLL;
    for (int i = L; i <= n; ++i){
        ans = max(ans, pref[i] - st.query(i - R, i - L));
    }
    cout << ans << endl;
    return 0;
}