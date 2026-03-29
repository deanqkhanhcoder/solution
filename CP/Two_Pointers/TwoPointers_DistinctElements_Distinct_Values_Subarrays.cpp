#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> v(n);
    for (auto &x : v) cin >> x;
    
    unordered_map<ll, int> m;
    ll ans = 0;
    for (int l = 0, r = 0; r < n; ++r) {
        int x = v[r];
        if (m.count(x) && m[x] >= l){
            l = m[x] + 1;
        }
        m[x] = r;
        ans += (r - l + 1);
    }
    cout << ans;
    return 0;
}