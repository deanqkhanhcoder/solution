#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("inline") 
#include <iostream> 
#include <vector>
#include <string>
using namespace std;
using ll = long long;
constexpr int MOD = (int)1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> dp1(n + 1, 0);
    vector<int> dp2(n + 1, 0);
    dp1[0] = 1;
    for (int i = 1; i <= n; ++i){
        char cur = s[i - 1];
        fill(dp2.begin(), dp2.end(), 0);
        for (int j = 0; j <= n; ++j){
            if (cur == '(' || cur == '?'){
                if (j > 0) dp2[j] = ((ll)dp2[j] + dp1[j - 1]) % MOD;
            }
            if (cur == ')' || cur == '?'){
                if (j + 1 <= n) dp2[j] = ((ll)dp2[j] + dp1[j + 1]) % MOD;
            }
        }
        dp1 = dp2;
    }
    cout << dp1[0];
    return 0;
}