#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr ll INF = (ll)1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "BAI05"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int N, M, P, T, B;
    cin >> N >> M >> P >> T >> B;
    vector<int> a, b;
    a.push_back(1);
    b.push_back(1);
    for (int i = 0; i < M; ++i){
        int c; cin >> c;
        a.push_back(c);
    }
    for (int i = 0; i < P; ++i){
        int c; cin >> c;
        b.push_back(c);
    }
    a.push_back(N);
    b.push_back(N);
    M += 2;
    P += 2;
    ll ans = 0;
    auto dist = [&](int pos){
        auto it = lower_bound(b.begin(), b.end(), pos);
        int dis = INT_MAX;
        if (it != b.end()){
            dis = min(dis, *it - pos);
        }
        if (it != b.begin()){
            it--;
            dis = min(dis, pos - *it);
        }
        return dis;
    };
    for (int i = 1; i < M; ++i){
        int u = a[i - 1];
        int v = a[i];
        if (u == v) continue;
        ll cost1 = 1LL * abs(v - u) * T;
        int distu = dist(u);
        int distv = dist(v);
        // cerr << "distu: " << distu << " distv: " << distv << endl;
        ll cost2 = 1LL * (distu + distv) * T + B;
        ans += min(cost1, cost2);
    }
    cout << ans;
    return 0;
}
