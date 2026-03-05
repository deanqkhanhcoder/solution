#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using ll = long long;
constexpr int MAXN = (int)1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    bitset<MAXN + 1> mod;
    for (int i = 0; i < n; ++i){
        ll a; cin >> a;
        mod[i] = a % 2;
    }
    vector<int> suf(n, 0);
    suf[n - 1] = (mod[n - 1] ? 0 : 1);
    for (int i = n - 2; i >= 0; --i){
        suf[i] = suf[i + 1] + (mod[i] ? 0 : 1);
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i){
        if (mod[i] == 0){
            ans += n - i - 1;
        } else {
            ans += suf[i + 1];
        }
        // cerr << ans << endl;
    }
    cout << ans;
}