#pragma GCC optimize ("Ofast") 
#pragma GCC optimize ("unroll-loops") 
#pragma GCC optimize ("inline")
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("NUMBER3.INP", "r", stdin);
    freopen("NUMBER3.OUT", "w", stdout);
    static bitset<10000001> ip;
    ll l, r;
    cin >> l >> r;

    int LIMIT = sqrtl(r);

    vector<int> pr;
    pr.reserve(LIMIT / 10);
    ip.set();
    ip[0] = ip[1] = 0;

    for (int i = 2; i <= LIMIT; i++) {
        if (ip[i]) pr.push_back(i);
        for (int p : pr) {
            ll x = 1LL * p * i;
            if (x > LIMIT) break;
            ip[x] = 0;
            if (i % p == 0) break;
        }
    }
    int i = upper_bound(pr.begin(), pr.end(), int(sqrtl(l))) - pr.begin();
    int cnt = (int)pr.size() - i;
    cout << cnt;
}
