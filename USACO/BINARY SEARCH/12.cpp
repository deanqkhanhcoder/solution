#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
struct Fenwick {
    int n;
    vector<int> BIT;
    Fenwick(int n) : n(n), BIT(n + 1, 0) {}
    Fenwick(vector<int> &a) : Fenwick(a.size()) {
        for (int i = 1; i <= n; ++i){
            BIT[i] += a[i - 1];
            int j = i + lowbit(i);
            if (j <= n) BIT[j] += BIT[i];
        }
    }
    void add(int i, int val){
        for (; i <= n; i += lowbit(i)){
            BIT[i] += val;
        }
    }
    int query(int i){
        int ans = 0;
        for (; i > 0; i -= lowbit(i)){
            ans += BIT[i];
        }
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "balancing"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    // code here
    int n; cin >> n;
    vector<pair<int, int>> cow(n);
    int MAXY = 0;
    for (pair<int, int> &p : cow){
        cin >> p.first >> p.second;
        MAXY = max(MAXY, p.second);
    } 
    Fenwick left(MAXY);
    Fenwick right(MAXY);
    for (pair<int, int> &p : cow) right.add(p.second, 1);
    int res = n;
    sort(all(cow));
    for (int i = 0; i < n;){
        int j = i;
        while (j < n && cow[i].first == cow[j].first){
            left.add(cow[j].second, 1);
            right.add(cow[j].second, -1);
            j++;
        }
        i = j;
        int lo = 0, hi = MAXY / 2 + 1; 
        while (lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int Y = mid * 2;
            int LD = left.query(Y);
            int LU = i - LD;
            int RD = right.query(Y);
            int RU = n - i - RD;
            int max_below = max(LD, RD);
            int max_above = max(LU, RU);
            res = min(res, max(max_below, max_above));
            if (max_below < max_above) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    cout << res;
}