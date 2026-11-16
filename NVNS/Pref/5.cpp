#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr ll INFLL = (ll)1e18;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    string s; cin >> s;
    // int n = s.length();
    vector<string> alive;
    string curr = "";
    for (char c : s){
        if (c == 'a' || c == 'b' || c == 'c'){
            curr += c;
        } else {
            if (curr != ""){
                alive.push_back(curr);
                curr = "";
            }
        }
    }
    if (curr != ""){
        alive.push_back(curr);
        curr = "";
    }
    ll ans = 0;
    for (string &curr : alive) {
        int m = curr.length();
        // cerr << "curr : " << curr << endl;
        // cerr << "m : " << m << endl;
        int pref = 0;
        vector<ll> cnt(2 * m + 5);
        int offset = m;
        cnt[offset] = 1;
        for (int i = 0; i < m; ++i) {
            pref += (curr[i] == 'a' ? 1 : curr[i] == 'b' ? -1 : 0);
            ans += cnt[pref + offset];
            cnt[pref + offset]++;
        }
    }
    cout << ans << endl;
    return 0;
}