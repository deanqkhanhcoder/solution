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
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    auto case1 = [&](){
        return (a[n - 2] - a[0] + 1 == n - 1) && (a[n - 1] - a[n - 2] > 2);
    };
    auto case2 = [&](){
        return (a[n - 1] - a[1] + 1 == n - 1) && (a[1] - a[0] > 2);
    };
    int ans_min = INF;
    if (case1() || case2()){
        ans_min = 2;
    } else {
        int r = 0;
        for (int l = 0; l < n; ++l){
            while(r < n - 1 && a[r + 1] - a[l] < n){
                r++;
            }
            // if (l > r) cout << "FUCK" << endl;
            ans_min = min(ans_min, n - (r - l + 1));
        }
    }
    int gap = 0;
    for (int i = 1; i < n; ++i) gap += a[i] - a[i - 1] - 1;
    int ans_max = gap - min(a[n - 1] - a[n - 2] - 1, a[1] - a[0] - 1);
    cout << ans_min << endl << ans_max;
    return 0;
}