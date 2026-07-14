#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MAXA = (int)1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    vector<int> spf(MAXA + 1, 0);
    vector<int> omega(MAXA + 1, 0);
    vector<int> pr;
    for (int i = 2; i <= MAXA; ++i){
        if (spf[i] == 0){
            spf[i] = i;
            pr.push_back(i);
        }
        omega[i] = omega[i / spf[i]] + 1;
        for (int p : pr){
            if (1LL * i * p > MAXA) break;
            spf[i * p] = p;
            if (spf[i] == p) break;
        }
    }
    int a, b;
    while(cin >> a >> b){
        int g = __gcd(a, b);
        int ans = omega[a / g] + omega[b / g];
        cout << ans << endl;
    }
    return 0;
}