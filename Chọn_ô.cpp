#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;
const int NEG = (int)-1e9;
using ll = long long;
bool check(int mask){
    for (int i = 0; i < 3; ++i){
        if ((mask & (1 << i)) && (mask & (1 << (i + 1)))) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int maxest = NEG;
    vector<vector<int>> a(4, vector<int>(n));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < n; ++j){
            cin >> a[i][j];
            maxest = max(maxest, a[i][j]);
        }
    if (maxest <= 0){
        cout << maxest;
        return 0;
    }
    vector<int> v;
    v.reserve(16);
    for (int m = 0; m < 16; ++m)
        if (check(m)) v.push_back(m);
    vector<int> dp1(16, NEG);
    vector<int> dp2(16, NEG);
    dp1[0] = 0;
    for (int c = 0; c < n; ++c){
        for (int m : v){
            int sum = 0;
            for (int i = 0; i < 4; ++i)
                if (m & (1 << i)) sum += a[i][c];
            dp2[m] = NEG;
            for (int pm : v){
                if (m & pm) continue;
                dp2[m] = max(dp2[m], dp1[pm] + sum);
            }
        }
        dp1 = dp2;
    }
    int ans = 0;
    for (int i = 0; i < 16; ++i) ans = max(ans, dp1[i]);
    cout << ans;
    return 0;
}