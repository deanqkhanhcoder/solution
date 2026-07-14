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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int &e : a) cin >> e;
        string s; cin >> s;
        vector<int> pref(n + 1);
        pref[0] = 0;
        int p0 = 0, p1 = 0;
        for (int i = 1; i <= n; ++i){
            pref[i] = pref[i - 1] ^ a[i - 1];
            if (s[i - 1] == '0'){
                p0 ^= a[i - 1];
            } else {
                p1 ^= a[i - 1];
            }
        }
        int q; cin >> q;
        while(q--){
            int type; cin >> type;
            if (type == 1){
                int l, r; cin >> l >> r;
                p0 ^= (pref[r] ^ pref[l - 1]);
                p1 ^= (pref[r] ^ pref[l - 1]);
            } else {
                int g; cin >> g;
                cout << (g == 0 ? p0 : p1) << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}