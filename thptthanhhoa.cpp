#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
constexpr int MAXN = (int)1e6;
int cnt[MAXN];
int main(){
    freopen("CAU2.INP", 'r', stdin);
    freopen("CAU2.OUT", 'w', stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int ans = 0;
    while(n--){
        int a; cin >> a;
        cnt[a]++;
        ans = max(ans, cnt[a]);
    }
    cout << ans;
    return 0;
}
