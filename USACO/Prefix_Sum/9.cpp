#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int MOD = 2019;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> cnt(MOD, 0);
    cnt[0] = 1;
    ll ans = 0;
    int pref = 0;
    int pow10 = 1;
    auto d = [](const char& c){
        return c - '0';
    };
    for (int i = n - 1; i >= 0; --i){
        pref = (pref + d(s[i]) * pow10) % MOD;
        ans += cnt[pref];
        cnt[pref]++;
        if (i != 0) pow10 = (pow10 * 10) % MOD;
    }
    cout << ans;
    return 0;
}