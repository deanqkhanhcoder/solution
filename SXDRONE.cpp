#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    int cnt1 = 0;
    for (int &e : a){
        cin >> e;
        cnt1 += e == 1;
    }
    int ans = 0;
    for (int i = 0; i < cnt1; ++i) ans += a[i] == 2;
    cout << ans;   
}