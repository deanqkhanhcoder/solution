#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
constexpr int LIMIT = (int)1e6;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> spf(LIMIT + 1, 0);
    vector<int> pr;
    pr.reserve(80000);
    for (int i = 2; i <= LIMIT; ++i){
        if (spf[i] == 0){
            spf[i] = i;
            pr.push_back(i);
        }
        for (int &p : pr){
            if (1LL * i * p > LIMIT) break;
            spf[i * p] = p;
            if (p == spf[i]) break;
        }
    }
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    bitset<LIMIT + 1> tsp;
    for (int i = 0; i < m; ++i){
        int bi = b[i];
        while (bi > 1){
            int p = spf[bi];
            tsp[p] = 1;
            while (bi % p == 0) bi /= p;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int ai = a[i];
        bool ok = false;
        while (ai > 1){
            int p = spf[ai];
            if (tsp[p] == 1){
                ok = true;
                break;
            }
            while (ai % p == 0) ai /= p;
        }
        if (ok){
            continue;
        } else {
            ans++;
        }
    }
    cout << ans;
    return 0;
}