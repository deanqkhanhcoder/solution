#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr ll INFLL = (ll)1e18;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> pref(2 * n + 1);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];
    for (int i = 1; i <= n; ++i) pref[i + n] = pref[i + n - 1] + a[i];
    deque<int> dq;
    for (int i = 1; i <= n; ++i){
        while (!dq.empty() && pref[dq.back()] >= pref[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (pref[dq.front()] >= pref[i]){
            ans++;
        }
        if (!dq.empty() && dq.front() == i + 1){
            dq.pop_front();
        }
        int j = n + i + 1;
        while (!dq.empty() && pref[dq.back()] >= pref[j]){
            dq.pop_back();
        }
        dq.push_back(j);
    }
    cout << ans << endl;
    return 0;
}
