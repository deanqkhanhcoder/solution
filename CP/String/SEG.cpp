#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> l(n + 1, 0);
    vector<int> r(n + 1, 0);
    for (int i = 0; i < n; ++i){
        if (s[i] == '<') l[i + 1] = l[i] + 1;
    }
    for (int j = n; j >= 1; --j){
        if (s[j - 1] == '>') r[j - 1] = r[j] + 1;
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i){
        ans += max(l[i], r[i]);
    }
    cout << ans;
    return 0;
}