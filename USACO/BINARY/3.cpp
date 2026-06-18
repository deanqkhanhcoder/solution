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
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    const int MID = n / 2;
    for (int i = MID + 1; i < n; ++i){
        ll diff = 1LL * (i - MID) * (a[i] - a[i - 1]);
        if (diff <= k){
            k -= diff;
        } else {
            cout << a[i - 1] + k / (i - MID);
            return 0;
        }
    }
    cout << a[n - 1] + k / (MID + 1);
    return 0;
}