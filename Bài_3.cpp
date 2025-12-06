#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <bitset>
#include <vector>
const int limit = (int)1e7;
using namespace std;
bitset<limit + 1> ip;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    ip.set();
    ip[0] = ip[1] = 0;
    for (int i = 4; i <= limit; i += 2) ip[i] = 0;
    for (int i = 3; i * i <= limit; i += 2){
        if (ip[i])
            for (int j = i * i; j <= limit; j += 2 * i)
                ip[j] = 0;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        int sum = pref[v] - pref[u - 1];
        if (sum >= 2 && ip[sum])
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}