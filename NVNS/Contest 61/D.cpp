#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
int K, E, N;
struct store{
    int X, F, C, W;
    store(int X, int F, int C)
        : X(X), F(F), C(C), W(C + (E - X)) {}
    bool operator<(const store &o) const{
        return W < o.W;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    cin >> K >> E >> N;
    vector<store> point;
    for (int i = 0; i < N; ++i){
        int X, F, C; cin >> X >> F >> C;
        point.emplace_back(X, F, C);
    }
    sort(all(point));
    ll ans = 0;
    int needed = K;
    for (int i = 0; i < N; ++i){
        if (needed == 0) break;
        int buy = min(needed, point[i].F);
        ll cost = 1LL * buy * point[i].W;
        ans += cost;
        needed -= buy;
    }
    cout << ans;
}