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
constexpr int LIMIT = (int)1e9;
vector<pair<int, int>> factor = {{2, 29}, {3, 18}, {5, 12}};
vector<int> d;
void dfs(int idx, ll currd){
    if (idx == 3){
        d.push_back(currd);
        return;
    }
    int nextd = 1;
    for (int pow = 0; pow <= factor[idx].second; pow++){
        if (nextd > LIMIT / currd) break;
        dfs(idx + 1, currd * nextd);
        if (pow < factor[idx].second){
            nextd *= factor[idx].first;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("NUM5.INP", "r", stdin);
    freopen("NUM5.OUT", "w", stdout);
    dfs(0, 1);
    sort(all(d));
    // for (int i = 0; i < d.size(); ++i){
    //     cerr << d[i] << ' ';
    // }
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        if (n > d.back()){
            cout << "NO" << endl;
            continue;
        }   
        auto it = lower_bound(all(d), n);
        if (*it != n){
            cout << "NO" << endl;
            continue;
        }
        int idx = it - d.begin() + 1;
        cout << "YES " << idx << endl;
    }
    return 0;
}