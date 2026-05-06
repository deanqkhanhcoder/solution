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
using i128 = __int128_t;

void print_i128(i128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    while (x > 0) {
        s += (x % 10) + '0';
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    // code here
    ll n; cin >> n;
    if (n & 1){
        i128 ans = (i128)n * n + 1;
        ans /= 2;
        print_i128(ans);
    } else {
        ll half = n / 2;
        i128 val1 = (i128)half * n - half;
        i128 val2 = val1 + 1;
        i128 val3 = val1 + n;
        i128 val4 = val2 + n;
        i128 ans = val1 + val2 + val3 + val4;
        print_i128(ans);
    }
    return 0;
}