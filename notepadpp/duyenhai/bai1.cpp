#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> a;
    a.reserve(n);
    for (int i = 0; i < n; ++i){
        ll ai; cin >> ai;
        if (ai > 1) a.push_back(ai);
    }
    n = (int)a.size();
    if (n == 0){
        cout << 0;
        return 0;
    }
    unordered_set<ll> g;
    g.reserve(n * 2);
    g.max_load_factor(0.7);
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            ll u = gcd(a[i], a[j]);
            if (u > 1) g.insert(u);
        }
    }
    if (g.empty()){
        cout << 1;
        return 0;
    }
    int ans = 0;
    for (ll u : g){
        int cnt = 0;
        for (ll x : a){
            if (x % u == 0) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}