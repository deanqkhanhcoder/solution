#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
const int MOD = (int)1e9;

using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int s1 = n / 2;
    int s2 = n - s1;
    vector<int> sub1;
    sub1.reserve(1<<s1);
    for (int mask = 0; mask < (1<<s1); ++mask){
        ll sum = 0;
        for (int i = 0; i < s1; ++i){
            if (mask & (1<<i)) sum = (sum + a[i]) % MOD;
        }
        sub1.push_back(sum);
    }
    vector<int> sub2;
    sub2.reserve(1<<s2);
    for (int mask = 0; mask < (1<<s2); ++mask){
        ll sum = 0;
        for (int i = 0; i < s2; ++i){
            if (mask & (1<<i)) sum = (sum + a[s1 + i]) % MOD;
        }
        sub2.push_back(sum);
    }
    sort(sub2.begin(), sub2.end());
    int ans = 0;
    for (int s : sub1) {
        int t = MOD - s;
        auto idx = lower_bound(sub2.begin(), sub2.end(), t);
        if (idx != sub2.begin()){
            idx--;
            ans = max(ans, s + *idx);
        } else {
            ans = max(ans, (int)(((ll)s + *idx) % MOD));
        }
    }
    cout << ans;
    return 0;
}