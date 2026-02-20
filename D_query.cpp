#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#define lowbit(i) ((i) & -(i))
using namespace std;
using ll = long long;
constexpr int MAXA = (int)1e6;
vector<int> BIT;

int n;
void update(int pos, int val){
    for (; pos <= n; pos += lowbit(pos)){
        BIT[pos] += val;
    }
}

int query(int pos){
    int ans = 0;
    for (; pos > 0; pos -= lowbit(pos)){
        ans += BIT[pos];
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    BIT.resize(n + 1);
    int q; cin >> q;
    vector<vector<pair<int, int>>> quer(n + 1);
    for (int i = 1; i <= q; ++i){
        int l, r; cin >> l >> r;
        quer[r].push_back({l, i});
    }
    vector<int> ans(q + 1);
    vector<int> last(MAXA, -1);
    for (int i = 1; i <= n; ++i){
        if (last[a[i]] != -1){
            update(last[a[i]], -1);
        }
        update(i, 1);
        last[a[i]] = i;
        if (quer[i].empty()) continue;
        for (auto &p : quer[i]){
            int l = p.first;
            int id = p.second;
            ans[id] = query(i) - query(l - 1);
        }
    }
    for (int i = 1; i <= q; ++i){
        cout << ans[i] << '\n';
    }
    return 0;
}