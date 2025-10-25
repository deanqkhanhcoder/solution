#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <bitset>
#define endl "\n"
using namespace std;

const int limit = (int)1e7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bitset<limit + 1> ip;
    ip.set();
    ip[0] = ip[1] = 0;
    for (int i = 4; i <= limit; i += 2) ip[i] = 0;
    for (int i = 3; 1LL * i * i <= limit; i += 2)
        if (ip[i])  
            for (int j = i * i; j <= limit; j += 2 * i)
                ip[j] = 0;
    static int ds[limit + 1];
    for (int i = 1; i <= limit; ++i)
        ds[i] = ds[i / 10] + (i % 10);
    int l, r; cin >> l >> r;
    for (int i = l; i <= r; ++i)
        if (ip[i] && ip[ds[i]]) cout << i << ' ';
    return 0;
}
