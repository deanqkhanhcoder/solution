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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // code here
    int L, R; cin >> L >> R;
    vector<int> cnt_d(R + 1, 0);
    for (int i = 1; i <= R; ++i){
        for (int j = i * 2; j <= R; j += i){
            cnt_d[j] += i;
        }
    }
    vector<int> pref(R + 1, 0);
    for (int i = 1; i <= R; ++i){
        if (cnt_d[i] > i) pref[i] = 1;
        pref[i] += pref[i - 1];
    }
    cout << pref[R] - pref[L - 1] << endl;
    return 0;
}