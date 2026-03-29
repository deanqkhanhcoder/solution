#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

vector<vector<bool>> ip;
vector<vector<int>> match;
vector<vector<int>> cnt;
pair<ll, ll> res(const string& s){
    int n = s.length() - 1;
    ip.assign(n + 1, vector<bool>(n + 1, false));
    match.assign(n + 2, vector<int>(n + 2, 0));
    cnt.assign(n + 1, vector<int>(n + 1, 0));
    for (int len = 1; len <= n; ++len){
        for (int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            if (len == 1) ip[i][j] = true;
            else if (len == 2) ip[i][j] = (s[i] == s[j]);
            else ip[i][j] = (s[i] == s[j] && ip[i + 1][j - 1]);
        }
    }
    for (int i = 1; i <= n; ++i){
        int cot = 0;
        for (int j = i; j <= n; ++j){
            if (ip[i][j]) cot++;
            cnt[i][j] = cot;
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int k = n; k >= 1; --k){
            if (s[i] == s[k]) match[i][k] = 1 + match[i - 1][k + 1];
            else match[i][k] = 0;
        }
    }
    ll ans1 = 0;
    ll ans2 = 0;
    for (int i = 1; i < n; ++i){
        for (int j = i + 1; j <= n; ++j){
            ans1 += match[i][j];
        }
    }
    for (int i = 2; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            ans2 += match[i - 1][j] * cnt[i][j - 1];
        }
    }
    return {ans1, ans2};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    s = ' ' + s;
    t = ' ' + t;
    pair<ll, ll> ans1 = res(s);
    pair<ll, ll> ans2 = res(t);
    ll ans = ans1.first + ans1.second + ans2.second;
    cout << ans;
    return 0;
}