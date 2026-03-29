#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("THUGON.INP", "r", stdin);
    freopen("THUGON.OUT", "w", stdout);
    string s;
    while(cin >> s){
        int n = s.size();
        if (n == 1){
            cout << s << '\n';
            continue;
        }
        string ans;
        char last = s[0];
        int cnt = 1;
        for (int i = 1; i < n; ++i){
            if (last != s[i]){
                if (cnt > 1) ans += to_string(cnt);
                ans.push_back(last);
                cnt = 1;
                last = s[i];
            } else {
                cnt++;
            }
        }
        if (cnt > 1) ans += to_string(cnt);
        ans.push_back(last);
        cout << ans << '\n';
    }
    return 0;
}