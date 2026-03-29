#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using ll = long long;
constexpr int LIMIT = (int)1e6;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bitset<LIMIT + 1> pr;
    pr.set();
    pr[0] = pr[1] = 0;
    for (int i = 4; i <= LIMIT; i += 2) pr[i] = 0;
    for (int i = 3; i * i <= LIMIT; i += 2){
        if (pr[i]){
            for (ll j = i * i; j <= LIMIT; j += 2 * i){
                pr[j] = 0;
            }
        }
    }
    vector<int> pref(LIMIT + 1, 0);
    for (int i = 3; i <= LIMIT; i += 2){
        pref[i] = pref[i - 2] + pr[i];
    }
    int l, r; cin >> l >> r;
    r--;
    int f = max(2, 2 * l + 1);
    int s = 2 * r + 1;
    cout << pref[s] - pref[f - 2];
    return 0;
}