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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int T; cin >> T;
    while(T--){
        int n; ll s; cin >> n >> s;
        ll sum = 1LL * n * (n + 1) / 2;
        if (labs(s) > sum) {
            cout << 0 << '\n';
        }
        else if ((sum - s) % 2 != 0) {
            cout << 0 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
    }
    return 0;
}