#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <algorithm>
#define gcd(a,b) __gcd(a,b)
using namespace std;
using point = pair<int, int>;
using ll = long long;
point operator-(const point &a, const point &b){
    return make_pair(a.first - b.first, a.second - b.second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, k; cin >> a >> b >> k;
    point ab = make_pair(b, 0) - make_pair(0, a);
    int g = gcd(abs(ab.first), abs(ab.second));
    cerr << "g " << g << endl;
    int t = a + b + g;
    if (k == 1){
        cout << t;
        return 0;
    }
    ll ans = (1LL * a * b - t) / 2 + 1;
    cout << ans;
    return 0;
}

