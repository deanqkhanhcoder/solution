#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <cstring>
#include <vector>
const int limit = 31623;
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    static bool ip[limit + 1];
    memset(ip, 1, sizeof(ip));
    vector<int> pr;
    ip[0] = ip[1] = 0;
    pr.reserve(limit);
    for (int i = 2; i <= limit; ++i){
        if (ip[i]) pr.push_back(i);
        for (int p : pr){
            if (1LL * i * p > limit) break;
            ip[i * p] = 0;
            if (i % p == 0) break;
        }
    }
    ll ans = 1;
    for (int p : pr){
        if (1LL * p * p > n) break;
        if (n % p == 0){
            int cnt = 0;
            while (n % p == 0){
                cnt++;
                n /= p;
            }
            ans *= (cnt + 1);
        }
    }
    if (n > 1) ans *= 2;
    cout << ans;
    return 0;
}
