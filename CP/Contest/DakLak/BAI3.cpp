#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int ans = -1;
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i] - 'a'] == 1) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}