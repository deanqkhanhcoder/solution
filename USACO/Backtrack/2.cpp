#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int MAXA = 100;
struct crow{
    int s, t, c;
    crow() {}
    crow(int s, int t, int c) : s(s), t(t), c(c) {}
};
struct air{
    int a, b, p, m;
    air() {}
    air(int a, int b, int p, int m) : a(a), b(b), p(p), m(m) {}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int N, M; cin >> N >> M;
    vector<crow> r(N);
    for (int i = 0; i < N; ++i){
        int s, t, c; cin >> s >> t >> c;
        r[i] = crow(s, t, c);
    }
    vector<int> need(MAXA + 1, 0);
    for (int i = 0; i < N; ++i){
        need[r[i].s] += r[i].c;
        if (r[i].t + 1 <= MAXA) need[r[i].t + 1] -= r[i].c;
    }
    for (int i = 1; i <= MAXA; ++i){
        need[i] += need[i - 1];
    }
    vector<air> c(M);
    for (int i = 0; i < M; ++i){
        int a, b, p, m; cin >> a >> b >> p >> m;
        c[i] = air(a, b, p, m);
    }
    int ans = INT_MAX;
    const int LIMIT = 1 << M;
    for (int mask = 0; mask < LIMIT; ++mask){
        int cost = 0;
        vector<int> diff(MAXA + 1, 0);
        for (int i = 0; i < M; ++i){
            if ((mask & (1 << i)) == 0) continue;
            cost += c[i].m;
            diff[c[i].a] += c[i].p;
            if (c[i].b + 1 <= MAXA) diff[c[i].b + 1] -= c[i].p;
        }
        for (int i = 1; i <= MAXA; ++i){
            diff[i] += diff[i - 1];
            if (diff[i] < need[i]) goto done;
        }
        ans = min(ans, cost);
        done:;
    }
    cout << ans;
    return 0;
}