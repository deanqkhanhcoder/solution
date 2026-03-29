#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    ll sabs = 0;
    int cnt = 0;
    int minus = INT_MAX;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int x; cin >> x;
            if (x < 0) cnt++;
            sabs += abs(x);
            minus = min(minus, abs(x));
        }
    }
    cout << (cnt % 2 ? sabs - 2LL*minus : sabs);
    return 0;
}
