#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    string t = "#";
    for (char c : s) t += string(1, c) + "#";
    int m = 2*n + 1;
    vector<int> p(m, 0);
    int c = 0, R = 0;
    int ans = 0;
    for (int i = 0; i < m; ++i){
        int mrr = 2*c - i;
        if (i < R) p[i] = min(R - i, p[mrr]);
        int l = i - p[i];
        int r = i + p[i];
        while (l - 1 >= 0 && r + 1 < m && t[l - 1] == t[r + 1]) {
            p[i]++;
            l--;
            r++;
        }
        if (i + p[i] > R){
            c = i;
            R = i + p[i];
        }
        ans = max(ans, p[i]);
    }
    cout << ans;
}
