#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int cnt[5] = {};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    ans += cnt[4];
    int x = min(cnt[3], cnt[1]);
    ans += cnt[3];
    cnt[3] -= x;
    cnt[1] -= x;
    ans += cnt[2] / 2;
    cnt[2] %= 2;
    if (cnt[2]) {
        ans++;
        cnt[1] = max(0, cnt[1] - 2);
    }
    ans += (cnt[1] + 3) / 4;
    cout << ans << '\n';
    return 0;
}