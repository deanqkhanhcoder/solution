// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("inline")
// #include <iostream>
// using namespace std;
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int a, b, c , d;
//     cin >> a >> b >> c >> d;
//     if (b < a || d < c){
//         cout << 0;
//         return 0;
//     } else if (b < c){
//         ll ans = (ll)(b - a + 1) * (d - c + 1);
//         cout << ans;
//         return 0;
//     }
//     ll ans1 = (ll)(c - a)*(d - c + 1); // [a, c - 1] * [c, d]
//     if (d <= b){
//         cout << (ans1 < 0 ? 0 : ans1);
//         return 0;
//     }
//     int n = b - c + 1;
//     ll ans2 = (ll)n * d;
//     ll minus = (ll)(b + c) * n / 2;
//     ll ans = ans1 + ans2 - minus;
//     cout << (ans < 0 ? 0 : ans);
//     return 0;
// }
#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b < a || d < c){
        cout << 0;
        return 0;
    }
    ll ans = 0;
    ll L1 = a;
    ll R1 = min(b, c - 1);
    if (L1 <= R1){
        ll len1 = R1 - L1 + 1;
        ans += len1 * (d - c + 1);
    }
    ll L2 = max(a, c);
    ll R2 = min(b, d - 1);
    if (L2 <= R2){
        ll n = R2 - L2 + 1;
        ans += n * d;
        ans -= (L2 + R2) * n / 2;
    }

    cout << ans;
}
