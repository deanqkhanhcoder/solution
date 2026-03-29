#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cstring>
using namespace std;
using i16 = int16_t;

constexpr int MAXA = 5000;
constexpr int LIM = 67;
constexpr int SMALLP = 19;
constexpr int LIMIT = 1 << SMALLP;
constexpr int BITS = LIMIT - 1;
int k;
int spf[MAXA + 1];
int smallid[70];
int largeid[MAXA + 1];

void sieve(){
    vector<int> pr;
    pr.reserve(5000);
    for (int i = 2; i <= MAXA; ++i){
        if (spf[i] == 0){
            spf[i] = i;
            pr.push_back(i);
        }
        for (int &p : pr){
            if (i * p > MAXA) break;
            spf[i * p] = p;
            if (p == spf[i]) break;
        }
    }
    int cnt1 = 0, cnt2 = 1;
    k = 0;
    for (int &p : pr){
        if (p <= LIM){
            smallid[p] = cnt1++;
        } else {
            largeid[p] = cnt2++;
            k++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("COPRIME.INP", "r", stdin);
    // freopen("COPRIME.OUT", "w", stdout);
    sieve();
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<vector<int>> group(k + 1);
    int ans1 = 0;
    for (int &x : a){
        int t = x;
        int mask = 0;
        int gid = 0;
        while (t > 1){
            int p = spf[t];
            while (t % p == 0) t /= p;
            if (p <= LIM) mask |= (1 << smallid[p]);
            else {
                gid = largeid[p];
                if (gid != -1 && mask == 0){
                    ans1++;
                    largeid[p] = -1;
                    group[gid].clear();
                    gid = -1;
                }
                break;
            }
        }
        if (gid != -1) group[gid].push_back(mask);
    }
    for (vector<int> &g : group){
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
    }
    vector<i16> dp(LIMIT, 0), ndp(LIMIT, 0);
    for (int &mask : group[0]){
        int free = BITS ^ mask;
        for (int sub = free;; sub = (sub - 1) & free){
            int idx = sub | mask;
            dp[idx] = max(dp[idx], (i16)(dp[sub] + 1));
            if (sub == 0) break;

        }
    }
    for (int i = 1; i <= k; ++i){
        if (group[i].empty()) continue;
        memcpy(ndp.data(), dp.data(), sizeof(i16) * LIMIT);
        for (int &mask : group[i]){
            int free = BITS ^ mask;
            for (int sub = free;; sub = (sub - 1) & free){
                int idx = sub | mask;
                ndp[idx] = max(ndp[idx], (i16)(dp[sub] + 1));
                if (sub == 0) break;
            }
        }
        dp.swap(ndp);
    }
    int ans = 0;
    for (auto &j : dp) ans = max(ans, (int)(j));
    cout << ans + ans1;
    return 0;
}
