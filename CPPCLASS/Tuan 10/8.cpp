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
    int i = 0;
    for (; i < n; ++i){
        if (a[i] != n - i) break;
    }
    if (i == n){
        for (int x : a) cout << x << ' ';
        cout << endl;
        return 0;
    }
    int best = i + 1;
    for (int j = i + 2; j < n; ++j){
        if (a[j] > a[best]){
            best = j;
        }
    }
    swap(a[i], a[best]);
    for (int x : a) cout << x << ' ';
    cout << endl;
    return 0;
}