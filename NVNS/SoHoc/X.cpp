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
    // code here
    int T; cin >> T;
    while (T--){
        ll n; cin >> n;
        auto d = [](ll n) -> pair<int, int> {
            int cntp = 0;
            int d = 1;
            for (int i = 2; i * i <= n; ++i){
                if (n % i == 0){
                    cntp++;
                    int e = 0;
                    while(n % i == 0){
                        n /= i;
                        e++;
                    }
                    d *= (e + 1);
                }
            }
            if (n > 1){
                cntp++;
                d *= 2;
            }
            return {(d - 2 <= 0 ? 0 : d - 2), (d - 2 == 0 ? 0 : cntp)};
        };
        pair<int, int> ans = d(n);
        cout << ans.first << ' ' << ans.second << endl;
    }
    return 0;
}