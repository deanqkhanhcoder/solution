#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll NEG = (ll)-1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(1);
    a.reserve(n);
    for (int i = 0; i < n; ++i){
        int e; cin >> e;
        a.push_back(e);
    }
    vector<ll> keep[2] = {vector<ll>(k + 1, NEG), vector<ll>(k + 1, NEG)};
    vector<ll> rem[2] = {vector<ll>(k + 1, NEG), vector<ll>(k + 1, NEG)};
    keep[0][0] = 0;
    for (int i = 1; i <= n; ++i){
        fill(keep[1].begin(), keep[1].end(), NEG);
        fill(rem[1].begin(), rem[1].end(), NEG);
        for (int j = 0; j <= k; ++j){
            keep[1][j] = max(keep[0][j], rem[0][j]) + (ll)a[i];
            if (j == 0) continue;
            rem[1][j] = max(rem[0][j], keep[0][j - 1]);
        }
        swap(keep[0], keep[1]);
        swap(rem[0], rem[1]);
    }
    ll ans = NEG;
    for (int j = 0; j <= k; ++j){
        ans = max(ans, keep[0][j]);
        ans = max(ans, rem[0][j]);
    }
    cout << ans;
    return 0;
}