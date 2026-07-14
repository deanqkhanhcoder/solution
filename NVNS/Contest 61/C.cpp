#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int MOD = (int)1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> char_to_id;
    for (char c : s){
        char_to_id[c] = 1;
    }
    int k = 0;
    for (char c = 'a'; c <= 'z'; ++c){
        auto it = char_to_id.find(c);
        if (it != char_to_id.end()){
            it->second = k++;
        }
    }
    for (char c = 'A'; c <= 'Z'; ++c){
        auto it = char_to_id.find(c);
        if (it != char_to_id.end()){
            it->second = k++;
        }
    }
    if (k == 1){
        ll ans = 1LL * n * (n + 1) / 2;
        ans %= MOD;
        cout << ans;
        return 0;
    }
    map<vector<int>, int> diff;
    vector<int> curr_diff(k - 1, 0);
    diff[curr_diff] = 1;
    vector<int> cnt(k, 0);
    ll res = 0;
    for (int i = 0; i < n; ++i){
        int id = char_to_id[s[i]];
        cnt[id]++;
        if (id > 0){
            curr_diff[id - 1] = cnt[id] - cnt[id - 1];
        }
        if (id < k - 1){
            curr_diff[id] = cnt[id + 1] - cnt[id];
        }
        if (diff.count(curr_diff)){
            res += diff[curr_diff];
            if (res >= MOD) res +-= MOD;
        }
        diff[curr_diff]++;
    }
    cout << res;
    return 0;
}