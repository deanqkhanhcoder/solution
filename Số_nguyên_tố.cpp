#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
using i128 = __int128;
constexpr int LIMIT = (int)3e6;
bitset<LIMIT + 1> ip;
vector<int> pr;
int sieve(){
    pr.reserve(LIMIT);
    ip.set();
    ip[0] = ip[1] = 0;
    for (int i = 2; i <= LIMIT; ++i){
        if (ip[i]) pr.push_back(i);
        for (int &p : pr){
            if (1LL * i * p > LIMIT) break;
            ip[i * p] = 0;
            if (i % p == 0) break;
        }
    }
    return (int)pr.size();;
}
string tostring(i128 x){
    if (!x) return "0";
    string ans;
    while(x){
        ans += '0' + x % 10;
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m = sieve();
    int t; cin >> t;
    while(t--){
        string n; cin >> n;
        int k; cin >> k;
        i128 x = 0;
        for (char c : n) x = x * 10 + (c - '0');
        i128 ans = 1;
        for (int i = 0; i < k; ++i){
            if (ans > x / pr[i]) {
                ans = x + 1;
                break;
            }
            ans *= pr[i];
        }
        if (ans >= x){
            cout << -1 << "\n";
            continue;
        }
        for (int i = k; i < m; ++i){
            if (ans > (x * pr[i - k]) / pr[i]) break;
            ans /= pr[i - k];
            ans *= pr[i];
        }
        cout << tostring(ans) << "\n";
    }
    return 0;
}