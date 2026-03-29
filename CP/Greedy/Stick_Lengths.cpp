#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    sort(p.begin(), p.end());
    int median = p[n / 2];
    ll ans = 0;
    for (int x : p) ans += llabs(1LL * x - median);
    cout << ans;
}