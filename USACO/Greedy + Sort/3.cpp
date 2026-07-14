#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "highcard"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n; cin >> n;
    vector<bool> visited(2 * n + 1, false);
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        visited[x] = true;
    }
    vector<int> a, b;
    a.reserve(n);
    b.reserve(n);
    for (int i = 1; i <= 2 * n; ++i){
        if (visited[i]) a.push_back(i);
        else b.push_back(i);
    }
    /*
    1 4 6
    2 3 5
    */
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n && j < n; i++) {
        while (j < n && b[j] < a[i]) j++;
        if (j < n) {
            ans++;
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}