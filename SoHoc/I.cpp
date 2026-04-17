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
constexpr ll LIMIT = (ll)1e12;
constexpr int MAXP = (int)1e6;
constexpr int MAXQ = 40;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    ll L, R; cin >> L >> R;
    bitset<MAXP + 1> ip;
    ip.set();
    ip[0] = ip[1] = 0;
    vector<int> pr;
    for (int i = 2; i <= MAXP; ++i){
        if (ip[i]){
            pr.push_back(i);
        }
        for (int &p :pr){
            if (1LL * i * p > MAXP) break;
            ip[i * p] = 0;
            if (i % p == 0) break;
        }
    }
    vector<ll> satified;
    for (int p : pr){
        ll num = 1LL * p * p;
        satified.push_back(num);
        int lastm = 2;
        for (int q : pr){
            if (q <= 3) continue;
            if (q > 40) break;
            int mul = q - 1;
            for (int i = 1; i <= mul - lastm; i++){
                if (num > LIMIT / p) goto end;
                num *= p;
            }
            lastm = mul;
            satified.push_back(num);
        }
        end:;
    }
    sort(all(satified));
    auto it1 = lower_bound(all(satified), L);
    int cnt1 = it1 - satified.begin();
    auto it2 = upper_bound(all(satified), R);
    int cnt2 = it2 - satified.begin();
    cout << cnt2 - cnt1;
    return 0;
}