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
    int a, b; cin >> a >> b;
    auto pow = [](int b) -> int {
        int a = 10 % b;
        int power = 69;
        int res = 1;
        while (power){
            if (power & 1) res = (1LL * res * a) % b; 
            a = (1LL * a * a) % b;
            power >>= 1;
        } 
        return res;
    };
    a %= b;
    int r = (1LL * a * pow(b)) % b;
    int ans = (1LL * r * 10) / b;
    cout << ans;
    return 0;
}