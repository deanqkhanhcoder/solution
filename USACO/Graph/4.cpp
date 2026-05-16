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
constexpr int INF = (int)1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("hoofball.in", "r", stdin);
    // freopen("hoofball.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    auto jumping = [&](int idx){
        int left = (idx == 0 ? INF : a[idx] - a[idx - 1]);
        int right = (idx == n - 1 ? INF : a[idx + 1] - a[idx]);
        return (left <= right ? idx - 1 : idx + 1);
    };
    vector<int> in(n, 0);
    for (int i = 0; i < n; ++i){
        in[jumping(i)]++;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (in[i] == 0){
            ans++;
        } else if (i < jumping(i) && i == jumping(+(i)) && in[i] == 1 && in[jumping(i)] == 1){
            ans++;
        }
    }
    cout << ans;
}