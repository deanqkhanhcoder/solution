#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int MAXB = 2 * 3 * 5 * 7;
int MAXC;
vector<int> tag;
vector<int> ok;
void solve(ll v, ll k){
    ll cycle1 = (v - 1) / MAXB;
    ll red1 = (v - 1) % MAXB + 1;
    ll ans1 = cycle1 * MAXC + tag[red1];
    ll cycle2 = (k - 1) / MAXC;
    ll red2 = (k - 1) % MAXC;
    ll ans2 = cycle2 * MAXB + ok[red2];
    cout << ans1 << ' ' << ans2 << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    tag.assign(MAXB + 1, -1);
    int idx = 0;
    for (int i = 1; i <= MAXB; ++i){
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0){
            continue;
        } else {
            ok.push_back(i);
            tag[i] = ++idx;
        }
    }
    MAXC = idx;
    int q; cin >> q;
    while(q--){
        ll v, k; cin >> v >> k;
        solve(v, k);
    }
    return 0;
}