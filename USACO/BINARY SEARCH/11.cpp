#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define endl '\n'
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
    int n; cin >> n;
    vector<vector<int>> pos(n + 1);
    reference_wrapper<vector<int>> v = pos[0];
    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        pos[a].push_back(i);
    }
    vector<int> diff(n + 2, 0);
    auto get_group = [&](int x){
        auto &idx = v.get();
        int i = 0;
        int m = (int)idx.size();
        int cnt = 0;
        while(i < m){
            cnt++;
            int next_i = idx[i] + x;
            int next_pos = upper_bound(idx.begin() + i + 1, idx.end(), next_i) - idx.begin();
            i = next_pos;
        }
        return cnt;
    };
    auto solve = [&](auto &&self, int L, int R, int L_val, int R_val){
        if (L == R || L_val == R_val){
            diff[L] += L_val;
            diff[R + 1] -= L_val;
            return;
        }
        int MID = (L + R) / 2;
        int M_val1 = get_group(MID);
        int M_val2 = get_group(MID + 1);
        self(self, L, MID, L_val, M_val1);
        self(self, MID + 1, R, M_val2, R_val);
    };
    for (int lable = 1; lable <= n; ++lable){
        if (pos[lable].empty()) continue;
        v = pos[lable];
        int L_val = get_group(1);
        int R_val = get_group(n);
        solve(solve, 1, n, L_val, R_val);
    }
    int pref = 0;
    for (int i = 1; i <= n; ++i){
        pref += diff[i];
        cout << pref << endl;
    }
    return 0;
}