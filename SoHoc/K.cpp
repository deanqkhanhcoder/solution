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
constexpr int MAXA = (int)1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<int> spf(MAXA + 1, 0);
    // for (int i = 1; i <= MAXA; ++i) spf[i] = i;    
    vector<int> pr;
    for (int i = 2; i <= MAXA; i++){
        if (spf[i] == 0){
            spf[i] = i;
            pr.push_back(i);
        }
        for (int p : pr){
            if (1LL * i * p > MAXA) break;
            spf[i * p] = p;
            if (spf[i] == p) break;
        }
    }
    auto factor = [&](int x){
        int res = 1;
        while (x > 1){
            int p = spf[x];
            while (x % p == 0) x /= p;
            res *= p;
        }
        return res;
    };
    static int cnt[MAXA + 1];
    for (int i = 0; i < n; ++i){
        int rad = factor(a[i]);
        cnt[rad]++;
    }
    ll ans = 0;
    for (int i = 1; i <= MAXA; ++i){
        ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans;
    return 0;
}