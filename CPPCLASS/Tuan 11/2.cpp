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
struct Node {
    int s, p, q;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n; cin >> n;
    vector<Node> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i].s;
    for (int i = 1; i <= n; ++i) cin >> a[i].p;
    for (int i = 1; i <= n; ++i) cin >> a[i].q;
    constexpr int LOG = 20;
    vector<vector<int>> up_jump(n + 5, vector<int>(LOG));
    vector<vector<int>> down_jump(n + 5, vector<int>(LOG));
    vector<int> st;
    for (int i = 1; i <= n; ++i){
        while(!st.empty() && a[st.back()].s < a[i].s){
            up_jump[st.back()][0] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while(!st.empty()){
        up_jump[st.back()][0] = n + 1;
        st.pop_back();
    }
    up_jump[n + 1][0] = n + 1;
    up_jump[0][0] = 1;
    for (int i = n; i >= 1; --i){
        while (!st.empty() && a[st.back()].s > a[i].s){
            down_jump[st.back()][0] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while(!st.empty()){
        down_jump[st.back()][0] = 0;
        st.pop_back();
    }
    down_jump[0][0] = 0;
    down_jump[n + 1][0] = n;
    for (int j = 1; j < LOG; ++j){
        for (int i = 0; i <= n + 1; i++){
            up_jump[i][j] = up_jump[up_jump[i][j - 1]][j - 1];
            down_jump[i][j] = down_jump[down_jump[i][j - 1]][j - 1];
        }
    }
    auto get_up = [&](int u, int k){
        k = min(k, n + 1);
        for (int j = LOG - 1; j >= 0; --j){
            if ((k >> j) & 1){
                u = up_jump[u][j];
            }
        }
        return u;
    };
    auto get_down = [&](int u, int k){
        k = min(k, n + 1);
        for (int j = LOG - 1; j >= 0; --j){
            if ((k >> j) & 1){
                u = down_jump[u][j];
            }
        }
        return u;
    };
    for (int i = 1; i <= n; ++i){
        int pos1 = get_up(i, a[i].p);
        int res1 = get_down(pos1, a[i].q);
        int pos2 = get_down(i, a[i].q);
        int res2 = get_up(pos2, a[i].p);
        int ans = max(res1, res2);
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}