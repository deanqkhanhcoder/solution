#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> num(n);
        for (int &e : num) cin >> e;
        auto ceil = [](int a, int b){
            return (a + (b - 1)) / b;
        };
        int l = INF;
        int r = -INF;
        for (int i = 0; i < n - 1; ++i){
            int a = num[i];
            int b = num[i + 1];
            if (a < b){
                l = min(l, (a + b) / 2);
            } else if (a > b){
                r = max(r, ceil(a + b, 2));
            }
        r = max(r, 0);        }

        cout << (r <= l ? r : -1) << endl;
    }
    return 0;
}