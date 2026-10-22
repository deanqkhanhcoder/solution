#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define endl '\n'
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
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    if (n <= 2){
        cout << 0 << endl;
        return 0;
    }
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int i, int j){
        return a[i] > a[j];
    });
    vector<bool> active(n, false);
    ll ans = min(a[0], a[n - 1]);
    int k = 0, b = 0, C = 0;
    int i = 0;
    while (i < n){
        int j = i;
        int val = a[id[i]];
        while (j < n && a[id[j]] == val){
            int idx = id[j];
            int L = (idx - 1 + n) % n;
            int R = (idx + 1) % n;
            if (active[L]) b++;
            if (active[R]) b++;
            active[idx] = true;
            k++;
            j++;
        }
        int oldC = C;
        C = 2 * k - b - 3;
        C = max(C, 0); 
        C = min(C, n - 3);
        ans += 1LL * val * (C - oldC);
        i = j;
    }
    cout << ans << endl;
    return 0;
}