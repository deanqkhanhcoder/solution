#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
using ll = long long;

int n, k;
vector<ll> prefix;

bool check(ll limit) {
    int cnt = 0, pos = 0;
    while (pos < n) {
        ll target = prefix[pos] + limit;
        int r = upper_bound(prefix.begin(), prefix.end(), target) - prefix.begin() - 1;
        if (r == pos) return false;
        pos = r;
        if (++cnt > k) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    prefix.assign(n + 1, 0);

    ll l = 0;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        prefix[i] = prefix[i - 1] + x;
        l = max(l, x);
    }
    ll r = prefix[n];
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}
