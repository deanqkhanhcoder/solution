#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int MAXA = 1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    static int d[MAXA];
    for (int i = 1; i <= MAXA; ++i){
        for (int j = i; j <= MAXA; j += i){
            d[j] += i;
        }
    }
    int n; cin >> n;
    while (n--){
        int a; cin >> a;
        cout << d[a] << ' ';
    }
    return 0;
}