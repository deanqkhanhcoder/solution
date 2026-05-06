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
    int a, b;
    ll k;
    int p; 
    cin >> a >> b >> k >> p;
    auto pow = [](ll k, int MOD) -> ll{
        int a = 10 % MOD;
        ll b = k - 1;
        ll res = 1;
        while (b){
           if (b & 1) res = (1LL * res * a) % MOD;
           a = (1LL * a * a) % MOD; 
           b >>= 1;
        }
        return res;
    };
    vector<int> power(p);
    power[0] = pow(k, b);
    for (int i = 1; i < p; ++i){
        power[i] = (power[i - 1] * 10) % b;
    }
    a %= b;
    for (int i = 0; i < p; ++i){
       int remain = (1LL * a * power[i]) % b;
       int d = (remain * 10) / b;
       cout << d;
    }
    return 0;
}