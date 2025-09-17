#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    unordered_map<int,int> cnt;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x]++;
    }
    int ans = 1;
    for (auto &p : cnt) {
        ans = (ans * ((p.second + 1LL) % MOD )) % MOD;
    }
    ans = (ans - 1 + MOD) % MOD;
    cout << ans;
    return 0;
}
