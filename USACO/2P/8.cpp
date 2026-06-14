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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    // code here
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    ll sub = 1LL * n * (n + 1) / 2;
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        ll over = 1LL * (i + 1) * (n - i);
        if (a[i] == b[i]) ans += sub - over;
    }
    vector<vector<int>> posA(n + 1);
    vector<vector<int>> posB(n + 1);
    auto dist = [&](int i){
        return min(i + 1, n - i);
    };
    for (int i = 0; i < n; ++i){
        posA[a[i]].push_back(dist(i));
        posB[b[i]].push_back(dist(i));
    }
    for (int num = 1; num <= n; ++num){
        if (posA[num].empty() || posB[num].empty()) continue;
        vector<int> &dA = posA[num];
        vector<int> &dB = posB[num];
        sort(all(dA));
        sort(all(dB));
        int l = 0;
        ll pref = dB[l];
        for (int r = 0; r < (int)size(dA); ++r){
            if (dB[l] >= dA[r]){
                ans += 1LL * size(dB) * dA[r];
                continue;
            }
            while (l + 1 < (int)size(dB) && dB[l + 1] < dA[r]){
                l++;
                pref += dB[l];
            }
            ans += pref + 1LL * ((int)size(dB) - l - 1) * dA[r];
        }
    }
    cout << ans;
    return 0;
}