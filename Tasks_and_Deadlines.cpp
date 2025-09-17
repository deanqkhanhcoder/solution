#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for (auto &p : v) cin >> p.first >> p.second;
    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    });
    ll curr = 0, ans = 0;
    for (auto [d, dl] : v) ans += dl - (curr += d);
    cout << ans;
    return 0;
}