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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int t; cin >> t;
    auto d = [](const char& c){
        return c - 'a';
    };
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        if (n % 2 == 0){
            vector<int> cntOdd(26, 0);
            vector<int> cntEven(26, 0);
            int maxOdd = 0;
            int maxEven = 0;
            for (int i = 0; i < n; ++i){
                if (i & 1){
                    int idx = d(s[i]);
                    cntEven[idx]++;
                    maxEven = max(maxEven, cntEven[idx]);
                } else {
                    int idx = d(s[i]);
                    cntOdd[idx]++;
                    maxOdd = max(maxOdd, cntOdd[idx]);
                }
            }
            cout << (n - maxEven - maxOdd) << endl;
        } else {
            vector<vector<int>> pref_even(n, vector<int>(26, 0));
            vector<vector<int>> pref_odd(n, vector<int>(26, 0));
            vector<vector<int>> suff_even(n, vector<int>(26, 0));
            vector<vector<int>> suff_odd(n, vector<int>(26, 0));
            pref_odd[0][d(s[0])] = 1;
            for (int i = 1; i < n; ++i){
                pref_even[i] = pref_even[i - 1];
                pref_odd[i] = pref_odd[i - 1];
                if (i & 1) {
                    pref_even[i][d(s[i])]++;
                } else {
                    pref_odd[i][d(s[i])]++;
                }
            }
            suff_odd[n - 1][d(s[n - 1])] = 1;
            for (int i = n - 2; i >= 0; --i){
                suff_even[i] = suff_even[i + 1];
                suff_odd[i] = suff_odd[i + 1];
                if (i & 1) {
                    suff_even[i][d(s[i])]++;
                } else {
                    suff_odd[i][d(s[i])]++;
                }
            }
            int ans = n;
            for (int i = 0; i < n; ++i){
                int max_even = 0;
                int max_odd = 0;
                for (int c = 0; c < 26; ++c){
                    int curr_even = (i == 0 ? 0 : pref_even[i - 1][c]) + (i == n - 1 ? 0 : suff_odd[i + 1][c]);
                    int curr_odd = (i == 0 ? 0 : pref_odd[i - 1][c]) + (i == n - 1 ? 0 : suff_even[i + 1][c]);
                    max_even = max(max_even, curr_even);
                    max_odd = max(max_odd, curr_odd);
                }
                int replace = n - 1 - max_even - max_odd;
                ans = min(ans, replace + 1);
            }
            cout << ans << endl;
        }
    }
    return 0;
}