#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string out;
    out.reserve(30 * n);
    while (n--) {
        ll a, b; cin >> a >> b;
        ll q = a / b;
        ll f = q * b;
        ll s = (a % b == 0 ? a : (q + 1) * b);
        out += to_string(f);
        out.push_back(' ');
        out += to_string(s);
        out.push_back('\n');
    }
    cout << out;
    return 0;
}