#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        auto solve = [&](auto &&self, vector<int> &a, int pos) -> int {
            if (pos < 0) return 0;
            vector<int> s0, s1;
            for (int val : a){
                if ((val >> pos) & 1) {
                    s1.push_back(val);
                } else {
                    s0.push_back(val);
                }
            }
            if (s0.empty()) return self(self, s1, pos - 1);
            if (s1.empty()) return self(self, s0, pos - 1);
            return (1 << pos) + min(self(self, s0, pos - 1), self(self, s1, pos - 1)); 
            // cerr << "dm" << endl;
        };
        cout << solve(solve, a, 29) << endl;
    }
    return 0;
}