#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    constexpr int k = 2;
    unordered_map<ll, int> cnt;
    ll ans = 0;
    int l = 0;
    for (int r = 0; r < n; ++r){
        cnt[a[r]]++;
        while (cnt[a[r]] > k){
            cnt[a[l]]--;
            l++;
        }
        ans += (r - l + 1);
    }
    cout << ans;
    return 0;
}
