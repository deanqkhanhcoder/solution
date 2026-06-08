#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("whatbase.in", "r", stdin);
    freopen("whatbase.out", "w", stdout);
    int t; cin >> t;
    while (t--){
        int abc, def; cin >> abc >> def;
        ll a = abc / 100, b = (abc / 10) % 10, c = abc % 10;
        ll d = def / 100, e = (def / 10) % 10, f = def % 10;
        
        auto calc = [&](ll X) -> ll {
            return a * X * X + b * X + c;
        };
        
        auto solve = [&](ll num) -> ll {
            ll fi = d;
            ll se = e;
            ll th = f - num;
            ll delta = se * se - 4LL * fi * th; 
            if (delta < 0){
                return -1;
            } else {
                ll sq = (ll)round(sqrt(delta));
                if (sq * sq != delta) return -1; 
                ll bot = 2LL * fi;
                ll x1 = -1, x2 = -1;
                ll top1 = -se + sq;
                if (top1 % bot == 0) {
                    ll res1 = top1 / bot;
                    if (res1 >= 10 && res1 <= 15000) x1 = res1;
                }
                ll top2 = -se - sq;
                if (top2 % bot == 0) {
                    ll res2 = top2 / bot;
                    if (res2 >= 10 && res2 <= 15000) x2 = res2;
                }
                if (x1 != -1) return x1;
                if (x2 != -1) return x2;
                return -1;
            }
        };
        
        for (int X = 10; X <= 15000; ++X){
            ll num = calc(X);
            ll Y = solve(num);
            if (Y != -1){
                cout << X << " " << Y << endl;
                break;
            }
        }
    }
    return 0;
}