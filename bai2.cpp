#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    unordered_map<int, int> mp;
    mp[0] = -1;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == 'V') cnt++;
        else cnt -= 2;
        if (mp.count(cnt)) {
            ans = max(ans, i - mp[cnt]);
        } else {
            mp[cnt] = i;
        }
    }
    cout << ans;
}