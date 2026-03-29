#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; ll S; cin >> n >> S;
    vector<pair<int, int>> a(n);
    for (auto &p : a) cin >> p.first >> p.second;
    sort(a.begin(), a.end(), [](auto &a, auto &b){
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    int ans = 0;
    for (auto &p : a){
        // cerr << "p.first " << p.first << " p.second " << p.second << endl;
        if (S >= p.first){
            ans++;
            S += p.second;
        } else {
            break;
        }
    }
    cout << ans;
    return 0;
}