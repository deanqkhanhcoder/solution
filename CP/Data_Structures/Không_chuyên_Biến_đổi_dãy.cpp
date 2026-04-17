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
    int n, m; cin >> n >> m;
    vector<int> b(n);
    for (int &e : b) cin >> e;
    ll total = 0;
    ll s0 = 0;
    vector<int> diff(m + 1);
    for (int i = 0; i < n - 1; ++i){
        auto distance = [=](int a, int b) -> int {
            return (b - a + m) % m;
        };
        int d = distance(b[i], b[i + 1]);
        total += d;
        if (d <= 1) continue;
        int y = b[i + 1];
        int d0 = distance(0, y);
        s0 += max(0LL, 0LL + d - 1 - d0);
        // 1 + distance(x, b[i + 1]) <= d - 1
        // distance(x, b[i + 1]) <= d - 2
        // b[i + 1] - x <= d - 2
        // x >= b[i + 1] - d + 2
        // l = b[i + 1] - (d - 2)
        int l = (y - (d - 2) + m) % m;
        int r = y;
        if (l <= r){
            diff[l] += 1;
            diff[r + 1] -= 1;
        }
        else {
            diff[1] += 1;
            diff[r + 1] -= 1;
            diff[l] += 1;
            diff[m] -= 1;
        }
        int next = (y + 1) % m;
        diff[next] -= (d - 1);
        diff[next + 1] += (d - 1);
    }
    // cerr << "diff : ";
    // for (int i = 0; i < m; ++i) cerr << diff[i] << ' ';
    // cerr << endl;
    vector<ll> pref(m);
    pref[0] = diff[0];
    for (int i = 1; i < m; ++i){
        pref[i] = pref[i - 1] + diff[i];
    }
    ll maxs = s0;
    ll curr = s0;
    for (int i = 1; i < m; ++i){
        curr += pref[i];
        maxs = max(maxs, curr);
    }
    cout << total - maxs;
    return 0;
}