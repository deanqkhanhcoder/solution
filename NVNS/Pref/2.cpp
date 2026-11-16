#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    string s; cin >> s;
    int n = s.length();
    int sum = 0;
    for (char c : s){
        sum += (c - '0');
    }
    vector<array<int, 3>> cnt(n + 1);
    cnt[0][0] = 1;
    int pref = 0;
    for (int i = 1; i <= n; ++i){
        cnt[i][0] = cnt[i - 1][0];
        cnt[i][1] = cnt[i - 1][1];
        cnt[i][2] = cnt[i - 1][2];
        pref = (pref + (s[i - 1] - '0')) % 3;
        cnt[i][pref]++;
    }
    ll ans = 0;
    pref = 0;
    for (int i = 1; i <= n; ++i){
        pref = (pref + (s[i - 1] - '0')) % 3;
        int need = ((pref - sum) % 3 + 3) % 3;
        ans += cnt[i - 1][need];
    }
    ans--;
    if (sum % 3 == 0) ans++;
    cout << ans << endl;
    return 0;
}