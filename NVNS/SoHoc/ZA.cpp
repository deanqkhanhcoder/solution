#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int MAXA = (int)1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    bitset<MAXA + 1> ip;
    vector<int> pr;
    vector<int> F(MAXA + 1, 1);
    vector<int> cnt2(MAXA + 1, 0);
    vector<int> cnt5(MAXA + 1, 0);
    ip.set();
    ip[0] = ip[1] = 0;
    for (int i = 2; i <= MAXA; ++i){
        if (ip[i]){
            pr.push_back(i);
            ll pk = i;
            while (pk <= MAXA){
                if (i == 2) cnt2[pk] = 1;
                else if (i == 5) cnt5[pk] = 1;
                else F[pk] = i;
                if (pk > MAXA / i) break;
                pk *= i;
            }
        }
        for (int p : pr){
            if (1LL * i * p > MAXA) break;
            ip[i * p] = 0;
            if (i % p == 0) break;
        }
    }
    int currf = 1;
    int curr2 = 0;
    int curr5 = 0;
    for (int i = 2; i <= MAXA; ++i){
        currf = (1LL * currf * F[i]) % 10;
        curr2 += cnt2[i];
        curr5 += cnt5[i];
        int pow = curr2 - curr5;
        int rem2 = 1;
        if (pow > 0){
            int cycle = (pow - 1) % 4;
            if (cycle == 0) rem2 = 2;
            if (cycle == 1) rem2 = 4;
            if (cycle == 2) rem2 = 8;
            if (cycle == 3) rem2 = 6;
        }
        F[i] = (1LL * currf * rem2) % 10;
    }
    int a;
    while (cin >> a){
        cout << F[a] << endl;
    }
}