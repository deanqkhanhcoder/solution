#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = (int)s.size();
    unordered_map<int, int> mp;
    mp.reserve(2 * n);
    mp.max_load_factor(0.7);
    mp[0] = 1;
    int cur = 0;
    ll res = 0;
    for (int i = 0; i < n; ++i){
        cur += (s[i] == '1' ? 1 : -1);
        res += mp[cur];
        mp[cur]++;
    }
    cout << res;
}