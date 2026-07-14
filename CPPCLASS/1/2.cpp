#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int n, k; cin >> n >> k;
    string s; cin >> s;
    auto get_id = [](char c){
        return c - 'a';
    };
    vector<bool> has(26, false);
    int ans = 0;
    for (char c : s) has[get_id(c)] = true;
    for (char c = 'a'; c <= 'z'; ++c){
        if (!has[get_id(c)]) continue;
        vector<int> freq(26, 0);
        int cnt = 0;
        int other = 0;
        int l = 0;
        for (int r = 0; r < n; ++r){
            if (s[r] == c){
                cnt++;
            } else {
                if (freq[get_id(s[r])]++ == 0) other++;
            }
            while (other > k) {
                if (s[l] == c){
                    cnt--;
                } else {
                    if (--freq[get_id(s[l])] == 0) other--;
                }
                l++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}