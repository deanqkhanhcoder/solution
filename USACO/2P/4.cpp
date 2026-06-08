#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int MAXN = (int)1e5;
constexpr int INF = (int)1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    // code here
    int t; cin >> t;
    vector<vector<int>> d(MAXN + 1);
    for (int i = 1; i <= MAXN; ++i){
        for (int j = i; j <= MAXN; j += i){
            if (i == 1) d[j].reserve(16);
            d[j].push_back(i);
        }
    }
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for (int &e : a) cin >> e;
        sort(all(a));
        vector<int> cnt(m + 1);
        int cnt_true = 0;
        auto add = [&](int pos, int val){
            if (pos > m) return;
            if (cnt[pos] == 0 && val == 1) cnt_true++;
            if (cnt[pos] == 1 && val == -1) cnt_true--;
            cnt[pos] += val;
        };
        int j = 0;
        int ans = INF;
        for (int i = 0; i < n; ++i){
            for (int pos : d[a[i]]){
                add(pos, 1);
            }
            while (j < i){
                for (int pos : d[a[j]]){
                    add(pos, -1);
                }
                if (cnt_true == m) j++;
                else {
                    for (int pos : d[a[j]]){
                        add(pos, 1);
                    }
                    break;
                }
            }
            if (cnt_true == m) ans = min(ans, a[i] - a[j]);
        }
        cout << (ans == INF ? -1 : ans) << endl;
    }
    return 0;
}