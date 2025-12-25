#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using ll = long long;
const int limit = (int)1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bitset<limit + 1> ip;
    ip.set();
    ip[0] = ip[1] = 0;
    for (int i = 4; i <= limit; i += 2) ip[i] = 0;
    for (int i = 3; 1LL * i * i <= limit; i += 2){
        if (ip[i])
            for (ll j = i * i; j <= limit; j += 2 * i)
                ip[j] = 0;
    }
    static int ds[limit + 1];
    for (int i = 1; i <= limit; ++i){
        ds[i] = ds[i / 10] + (i % 10);
    }
    int n; cin >> n;
    int ans = 0;
    while (n--){
        int a; cin >> a;
        if (ip[a] && ip[ds[a]]) ans += 1;
    }
    cout << ans;
    return 0;
}
