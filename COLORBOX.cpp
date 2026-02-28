#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int LIMIT = (int)1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    vector<bool> cnt1(LIMIT + 1, false);
    vector<bool> cnt2(LIMIT + 1, false);
    for (auto &e : a) cin >> e;
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i){
        if (cnt1[a[i]] == true) break;
        cnt1[a[i]] = true;
        l = i;
    }
    for (int j = n - 1; j >= 0; j--){
        if (cnt2[a[j]] == true) break;
        cnt2[a[j]] = true;
        r = j;
    }
    int j = n - 1;
    int ans = min(n - l - 1, r);
    for (int i = l; i >= 0; i--){
        for (; j >= r; --j){
            if (cnt1[a[j]]) break;
            ans = min(ans, j - i - 1);
        }
        cnt1[a[i]] = false;
    }
    cout << ans;
}