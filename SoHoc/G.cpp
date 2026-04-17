#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    static int cnt[10];
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        ll a; cin >> a;
        a %= 10;
        if (a != 0) ans += cnt[0];
        if (a == 2 || a == 4 || a == 6 || a == 8){
            ans += cnt[5];
        }
        if (a == 5){
            ans += cnt[2] + cnt[4] + cnt[6] + cnt[8];
        }
        if (a == 0){
            ans += i - 1;
        }
        cnt[a]++;
    }
    cout << ans;
}