#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;
const int MAX_N = 1e6;
int spf[MAX_N + 1];
vector<int> p;

void s(){
    p.reserve(80000);
    for (int i = 2; i <= MAX_N; ++i){
        if (spf[i] == 0){
            spf[i] = i;
            p.push_back(i);
        }
        for (int &e: p){
            if (1LL * e * i > MAX_N) break;
            spf[i * e] = e;
            if (e == spf[i]) break;
        }
    }
}

ll f(ll n){
    ll y = 1;
    while (n > 1){
        int p = spf[n];
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        if (cnt % 2) y *= p;
    }
    return y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    s();
    unordered_map<int, int> mp;
    ll ans = 0;
    for (int e: a){
        ll p = f(e);
        ans += mp[p];
        mp[p]++;
    }
    cout << ans;
    return 0;
}