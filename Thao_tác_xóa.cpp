#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <cstring>
using ll = long long;
using namespace std;
constexpr ll NEG = -1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &e: a) cin >> e;
    vector<ll> keep1(k + 1, NEG), keep2(k + 1, NEG);
    vector<ll> rem1(k + 1, NEG), rem2(k + 1, NEG);
    keep1[0] = 0;
    for (int i = 1; i <= n; ++i){
        fill(keep2.begin(), keep2.end(), NEG);
        fill(rem2.begin(), rem2.end(), NEG);
        for (int j = 0; j <= k; ++j){  
            keep2[j] = max(keep1[j], rem1[j]) + a[i - 1];
            if (j == 0) continue;
            rem2[j] = max(rem1[j], keep1[j - 1]);
        }
        swap(keep1, keep2);
        swap(rem1, rem2);
    }
    ll ans = NEG;
    for (int j = 0; j <= k; ++j) {
        ans = max(ans, keep1[j]);
        ans = max(ans, rem1[j]);
    }
    cout << ans;
}