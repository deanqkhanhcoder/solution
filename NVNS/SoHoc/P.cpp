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
constexpr int LIMIT = (int)1e7;
vector<int> spf(LIMIT + 1, 0);
vector<int> pr;
vector<pair<int, int>> factor;
int x;
int sizef;
ll dfs(int idx, ll currd){
    if (idx == sizef){
        ll n = (1LL * x * x) / currd;
        if (2 * x < n - currd){
            return (n + currd) % 2 == 0;
        } else {
            return 0;
        }
    }
    ll cnt = 0;
    ll nextd = 1;
    for (int pow = 0; pow <= factor[idx].second; pow++){
        if (currd * nextd > x) break;
        cnt += dfs(idx + 1, currd * nextd);
        if (pow < factor[idx].second){
            nextd *= factor[idx].first;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    cin >> x;
    int tempx = x;
    for (int i = 2; i <= LIMIT; ++i){
        if (spf[i] == 0){
            spf[i] = i;
            pr.push_back(i);
        }
        for (int p : pr){
            if (1LL * p * i > LIMIT) break;
            spf[i * p] = p;
            if (spf[i] == p) break;
        }
    }
    for (int i = 2; 1LL * i * i <= tempx; ++i){
        if (x <= LIMIT){
            while (tempx > 1){
                int p = spf[tempx];
                int cnt = 0;
                while (tempx % p == 0){
                    tempx /= p;
                    cnt++;
                }
                factor.push_back({p, cnt * 2});
            }
            break;
        }
        if (tempx % i){
            int cnt = 0;
            while (tempx % i == 0){
                tempx /= i;
                cnt++;
            }
            factor.push_back({i, cnt * 2});
        }
    }
    if (tempx > 1) factor.push_back({x, 2});
    sizef = (int)factor.size();
    cout << dfs(0 , 1);
    return 0;
}