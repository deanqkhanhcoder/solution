#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; int t, a, b;
    cin >> n >> t >> a >> b;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    int nlast = k[n - 1];
    sort(k.rbegin(), k.rend());
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (t - a >= (n - i - 1)*b ) {
            res += k[i];
            t -= a;
        } else {
            if (k[i] == nlast){
                nlast = -1;
            } else
             {
                t -= b;
            }
        }
    }
    cout << res;
    return 0;
}