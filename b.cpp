#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
constexpr int MOD = (int)1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = (int)s.size();
    vector<ll> prev(n + 1, 0);
    vector<ll> curr(n + 1, 0);
    prev[0] = 1;
    for (char c : s){
        memset(curr.data(), 0, (n + 1)*sizeof(ll));
        for (int i = 0; i <= n; ++i){
            if (c == '(' || c == '?'){
                if (i < n){
                    curr[i + 1] += prev[i]; 
                    curr[i + 1] %= MOD;
                }
            }
            if (c == ')' || c == '?'){
                if (i > 0){
                    curr[i - 1] += prev[i];
                    curr[i - 1] %= MOD;
                }
            }
        }
        swap(curr, prev);
    }
    cout << prev[0] % MOD;
    return 0;
}