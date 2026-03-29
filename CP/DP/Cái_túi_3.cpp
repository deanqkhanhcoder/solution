#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vector<int> w, v;
    for (int i = 0; i < n; i++) {
        int wi, vi, ai;
        cin >> wi >> vi >> ai;

        int base = 1;
        while (ai > 0) {
            int take = min(base, ai);
            ai -= take;
            w.push_back(wi * take);
            v.push_back(vi * take);
            base <<= 1;
        }
    }
    vector<int> dp(s + 1, 0);
    n = (int)w.size();
    for (int i = 0; i < n; i++) {
        for (int j = s; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[s];
}
