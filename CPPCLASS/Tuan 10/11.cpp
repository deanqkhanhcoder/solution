#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
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
    auto check = [&](int T){
        int curB = a[0] - T;
        for (int i = 1; i < n; ++i){
            curB = max(a[i] - T, curB + 1);
            if (curB > a[i] + T) return false;
        }
        return true;
    };
    int lo = 0, hi = INF;
    while (lo < hi){
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    int ansT = lo;
    vector<int> b(n);
    b[0] = a[0] - ansT;
    for (int i = 1; i < n; ++i){
        b[i] = max(a[i] - ansT, b[i - 1] + 1);
    }
    cout << ansT << endl;
    for (int &x : b) cout << x << ' ';
    cout << endl;
    return 0;
}