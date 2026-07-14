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
    int n; cin >> n;
    vector<int> a(n);
    ll ans = 0;
    for (int &e : a){
        cin >> e;
        ans -= e;
    }
    for (int i = 0; i < 30; ++i){
        int s = 0;
        vector<int> cnt(2, 0);
        cnt[0] = 1;
        for (int x : a){
            s ^= (x >> i) & 1;
            ans += cnt[s ^ 1] * 1LL << i;
            cnt[s]++;
        }
    }
    cout << ans << endl;
}