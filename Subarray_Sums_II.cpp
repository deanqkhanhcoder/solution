#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;

using ll = long long;
struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return x ^ FIXED_RANDOM;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    unordered_map<ll, int, custom_hash> mp;
    mp.reserve(2*n);
    mp.max_load_factor(0.7);
    ll sum = 0, ans = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
        if (mp.find(sum - x) != mp.end()) ans += mp[sum - x];
        mp[sum]++;
    }
    cout << ans;
}
