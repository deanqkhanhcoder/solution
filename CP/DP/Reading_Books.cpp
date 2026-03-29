#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int maxt = 0;
    ll prs = 0;
    for (int i = 0; i < n; ++i){
        int t; cin >> t;
        maxt = max(maxt, t);
        prs += t;
    }
    cout << max(2LL * maxt, prs);
}
