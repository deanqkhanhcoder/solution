#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define lowbit(x) ((x) & -(x))
using namespace std;
using ll = long long;
using i128 = __int128_t;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;
struct Node {
    ll t, cost;
};
struct FenwickTree{
    int n;
    vector<ll> cnt;
    vector<i128> sum;
    FenwickTree(int n) : n(n), cnt(n + 1, 0), sum(n + 1, 0) {}
    void add(int pos, ll c, i128 s){
        for (; pos <= n; pos += lowbit(pos)){
            cnt[pos] += c;
            sum[pos] += s;
        }
    }
    ll query_cnt(int pos) const {
        ll ans = 0;
        for (; pos > 0; pos -= lowbit(pos)){
            ans += cnt[pos];
        }
        return ans;
    }
    i128 query_sum(int pos) const {
        i128 ans = 0;
        for (; pos > 0; pos -= lowbit(pos)){

            
            ans += sum[pos];
        }
        return ans;
    }
    int find_prefix(i128 budget) const {
        if (n <= 0) return 0;
        int pos = 0;
        i128 cur_cost = 0;
        int jump = __lg(n);
        for (int step = 1 << jump; step > 0; step >>= 1){
            int nxt = pos + step;
            if (nxt <= n && cur_cost + sum[nxt] <= budget){
                pos = nxt;
                cur_cost += sum[nxt];
            }
        }
        return pos;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n; cin >> n;
    ll my_t, my_w; cin >> my_t >> my_w;
    vector<Node> teams(n - 1);
    vector<ll> costs;
    costs.reserve(n - 1);
    for (auto &[t, cost] : teams){
        ll w; cin >> t >> w;
        cost = w - t + 1;
        costs.push_back(cost);
    }
    sort(all(costs));
    costs.erase(unique(all(costs)), costs.end());
    FenwickTree BIT(sz(costs));
    auto add_bit = [&](ll cost){
        int idx = lower_bound(all(costs), cost) - costs.begin() + 1;
        BIT.add(idx, 1, (i128)cost);
    };
    auto get_remove = [&](ll budget) -> ll {
        if (budget <= 0) return 0;
        int p = BIT.find_prefix((i128)budget);
        ll cnt = BIT.query_cnt(p);
        i128 sum = BIT.query_sum(p);
        if (p < sz(costs)){
            ll cost = costs[p];
            ll alive = BIT.query_cnt(p + 1) - cnt;
            ll extra = min(alive, (ll)((i128)budget - sum) / cost);
            cnt += extra; 
        }
        return cnt;
    };
    sort(all(teams), [](const Node &a, const Node &b){
        return a.t > b.t;
    });
    ll best_rank = n;
    ll bad_teams = 0;
    auto update = [&](ll target){
        if (target > my_t) return;
        ll budget = my_t - target;
        ll remove = get_remove(budget);
        ll cur_rank = 1 + (bad_teams - remove);
        best_rank = min(best_rank, cur_rank);
    };
    int i = 0;
    for (; i < n - 1; ++i){
        if (teams[i].t <= my_t) break;
        add_bit(teams[i].cost);
        bad_teams++;
    }
    best_rank = 1 + bad_teams;
    for (; i < n - 1;){
        int j = i;
        ll cur_t = teams[j].t;
        update(cur_t);
        while (j < n - 1 && teams[j].t == cur_t) j++;
        for (int k = i; k < j; ++k){
            if (teams[k].t > 0) add_bit(teams[k].cost);
        }
        if (cur_t > 0) bad_teams += (j - i);
        i = j;
    }
    update(0);
    cout << best_rank << endl;
    return 0;
}