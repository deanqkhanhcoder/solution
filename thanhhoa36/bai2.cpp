#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("inline") 
#include <iostream> 
#include <string>
using namespace std;
bool check(char c){
    return c != 'A' && c != 'N' && c != 'H';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int n = (int)s.size();
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i){
            if (check(s[i])){
                curr++;
            } else {
                ans = max(ans, curr);
                curr = 0;
            }
        }
        ans = max(ans, curr);
        cout << (ans ? ans : -1) << '\n';
    }
    return 0;
}