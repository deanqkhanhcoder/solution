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
constexpr int OFFSET = 1e6;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int T; cin >> T;
    vector<int> cnt(OFFSET * 2 + 1, 0);
    while (T--){
        int n; cin >> n;
        string s; cin >> s;
        ll ans = 0;
        int currs = 0;
        cnt[0 + OFFSET] = 1;
        vector<int> history;
        history.reserve(n);
        history.push_back(0 + OFFSET);
        for (int i = 0; i < n; ++i){
            currs += s[i] - '0' -1;
            // cerr << "a[i] = " << a[i] << ' ';
            ans += cnt[currs + OFFSET];
            cnt[currs + OFFSET]++;
            history.push_back(currs + OFFSET);
        }
        cout << ans << endl;
        for (int pos : history) {
            cnt[pos] = 0;
        }
    }
    return 0;
}