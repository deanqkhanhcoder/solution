#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MAXA = (int)1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    vector<int> phi(MAXA + 1);
    for (int i = 2; i <= MAXA; ++i) phi[i] = i;
    for (int i = 2; i <= MAXA; ++i){
        if (phi[i] == i){
            for (int j = i; j <= MAXA; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }
    vector<vector<int>> div(MAXA + 1);
    for (int i = 2; i <= MAXA; ++i){
        for (int j = i; j <= MAXA; j += i){
            div[j].push_back(i);
        }
    }
    /*
    n * (1 + for d : div[n] (d * o(d))/2
    */
    auto query = [&](int n){
        ll contribution = 1;
        for (int d : div[n]) contribution += 1LL * d * phi[d] / 2;
        contribution *= 1LL * n;
        return contribution;
    };
    int q; cin >> q;
    while (q--){
        int n; cin >> n;
        cout << query(n) << endl;
    }
    return 0;
}