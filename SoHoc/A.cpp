#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int MAXN = (int)1e7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "TRONGCAY"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    bitset<MAXN + 1> pr;
    pr.set();
    pr[0] = pr[1] = 0;
    for (int i = 4; i <= MAXN; i += 2) pr[i] = 0;
    for (int i = 3; i * i <= MAXN; i += 2){
        if (pr[i]){
            for (ll j = i * i; j <= MAXN; j += 2 * i){
                pr[j] = 0;
            }
        }
    }
    int n; cin >> n;
    vector<int> p;
    for (int i = 1; i <= n; ++i){
        int a; cin >> a;
        if (pr[a]) p.push_back(a);
    }
    int m = (int)p.size();
    if (m == 0){
        cout << -1;
        return 0;
    }
    sort(all(p));
    if (m % 2 == 0){
        for (int i = 0; i < m; i += 2){
            cout << p[i] << " ";
        }
        for (int i = m - 1; i >= 0; i -= 2){
            cout << p[i] << " ";
        }
    } else {
        for (int i = 1; i < m; i += 2){
            cout << p[i] << " ";
        }
        for (int i = m - 1; i >= 0; i -= 2){
            cout << p[i] << " ";
        }
    }
    return 0;
}