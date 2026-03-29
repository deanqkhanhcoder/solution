#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(string &s) {
    int n = s.size();
    ll totalSum = accumulate(s.begin(), s.end(), 0LL,
                              [](ll acc, char c) { return acc + (c - '0'); });
    array<ll,3> cnt = {0, 0, 0};
    ll prefixMod = 0;
    for (char c : s) {
        prefixMod = (prefixMod + (c - '0')) % 3;
        cnt[prefixMod]++;
    }

    ll res = 0;
    prefixMod = 0;
    for (int i = 0; i < n; ++i) {
        int needed = (totalSum + prefixMod) % 3;
        res += cnt[needed];
        prefixMod = (prefixMod + (s[i] - '0')) % 3; 
        cnt[prefixMod]--;
    }
    if (totalSum % 3 != 0) {
        res--;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}