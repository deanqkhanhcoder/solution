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
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k; 
        vector<int> a(n);
        vector<int> pos(n + 1);
        for (int i = 0; i < n; ++i){
            cin >> a[i];
            pos[a[i]] = i;
        }
        int m = 1;
        for (; m <= n - 1; ++m){
            if (pos[m] > pos[m + 1]) break;
        }
        cout << (n - m + k - 1) / k << endl;
    }
    return 0;
}