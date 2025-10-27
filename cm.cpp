#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
const int limit = 31623;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("SDB.INP", "r", stdin);
    freopen("SDB.OUT", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e: a) cin >> e;
    vector<char> ip(limit + 1, 1);
    vector<int> pr;
    pr.reserve(limit);
    ip[0] = ip[1] = 0;
    for (int i = 2; i <= limit; ++i){
        if (ip[i]) pr.push_back(i);
        for (int p : pr){
            if (1LL * i * p > limit) break;
            ip[i * p] = 0;
            if (i % p == 0) break;
        }
    }
    for (int e :a){
        int q = ceil(sqrt((double)e));
        auto it = *lower_bound(pr.begin(), pr.end(), q);
        ll p = it * it;
        cout << p << ' ';
    }
    return 0;
}