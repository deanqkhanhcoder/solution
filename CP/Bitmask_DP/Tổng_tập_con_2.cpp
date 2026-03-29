#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    int s1 = n / 2;
    int s2 = n - s1;
    vector<ll> sub1;
    sub1.reserve(1<<s1);
    for (int mask = 0; mask < (1<<s1); ++mask){
        ll sum = 0;
        for (int i = 0; i < s1; ++i){
            if (mask & (1<<i)) sum += a[i];
            if (sum > k) {sum = 1e18; break;}
        }
        if (sum <= k) sub1.push_back(sum);
    }
    vector<ll> sub2;
    for (int mask = 0; mask < (1<<s2); ++mask){
        ll sum = 0;
        for (int i = 0; i < s2; ++i){
            if (mask & (1<<i)) sum += a[s1 + i];
            if (sum > k) {sum = 1e18; break;}
        }
        if (sum <= k) sub2.push_back(sum);
    }
    sort(sub2.begin(), sub2.end());
    sub1.erase(unique(sub1.begin(), sub1.end()), sub1.end());
    sub2.erase(unique(sub2.begin(), sub2.end()), sub2.end());
    for (ll s : sub1) {
        ll t = k - s;
        if (binary_search(sub2.begin(), sub2.end(), t)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}