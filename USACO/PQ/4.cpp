#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <tuple>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
struct state {
    int time, cow, val;
    bool operator<(const state &o) const {
        return time < o.time;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "measurement"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n, g; cin >> n >> g;
    vector<state> a(n);
    unordered_map<int, int> mp;
    mp.reserve(2 * n);
    mp.max_load_factor(0.7);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].time >> a[i].cow >> a[i].val;
        mp[a[i].cow] = g;
    }
    sort(all(a));
    map<int, int> freq;
    freq[g] = n + 1; 
    int ans = 0;
    auto get = [&](int cow) -> tuple<int, int, int> {
        int milk = mp[cow];
        int maxest = freq.rbegin()->first;
        int cnt = freq.rbegin()->second;
        return {milk, maxest, cnt};
    };
    for (int i = 0; i < n; ++i) {
        int cow = a[i].cow;
        int val = a[i].val;
        auto [prev_milk, prev_max, prev_cnt] = get(cow);
        freq[prev_milk]--;
        if (freq[prev_milk] == 0) freq.erase(prev_milk);
        int &x = mp[cow];
        x += val;
        freq[x]++;
        auto [curr_milk, curr_max, curr_cnt] = get(cow);
        if (prev_milk == prev_max) { 
            if (curr_milk != curr_max){
                ans++;
            } else {
                if (prev_cnt != curr_cnt) ans++;
            }
        } else {
            if (curr_milk == curr_max) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}