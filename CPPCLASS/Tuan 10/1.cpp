#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n, k;
    ll b, c; cin >> n >> k >> b >> c;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a.begin() + 1, a.end());
    auto div5 = [&](ll val) -> pair<ll, int> {
        int q = val / 5;
        int r = val % 5;
        if (r < 0){
            q--;
            r += 5;
        }
        return {q, r};
    };
    vector<ll> prefA(n + 1);
    vector<ll> prefQ(n + 1);
    vector<array<int, 5>> prefCnt(n + 1);
    prefA[0] = 0;
    prefQ[0] = 0;
    for (int i = 1; i <= n; ++i){
        auto [q, r] = div5(a[i]);
        prefA[i] = prefA[i - 1] + a[i];
        prefQ[i] = prefQ[i - 1] + q;
        prefCnt[i] = prefCnt[i - 1];
        prefCnt[i][r]++;
    }
    ll B = min(b, 5 * c);
    ll ans = (1LL << 62);
    for (int i = k; i <= n; ++i){
        int l = i - k + 1;
        int x = a[i];
        auto [xq, rq] = div5(x);
        ll sumDiff = 1LL * k * x - (prefA[i] - prefA[l - 1]);
        ll sumDiv = 1LL * k * xq - (prefQ[i] - prefQ[l - 1]);
        int cnt = 0;
        for (int r = rq + 1; r <= 4; ++r){
            cnt += prefCnt[i][r] - prefCnt[l - 1][r];
        }
        sumDiv -= cnt;
        ll cost = 1LL * c * sumDiff + 1LL * (B - 5 * c) * sumDiv;
        ans = min(cost, ans);
    }
    cout << ans << endl;
    return 0;
}