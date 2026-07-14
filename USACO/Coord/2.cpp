#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #define TASK "haybales"
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    int n; cin >> n;
    map<ll, int> freq;
    for (int i = 0; i < n; ++i){
        ll l, r; cin >> l >> r;
        freq[l]++;
        freq[r + 1]--;
    }
    vector<ll> ans(n + 1, 0);
    int layer = freq.begin()->second;
    auto it = freq.begin();
    ++it;
    while (it != freq.end()){
        ans[layer] += (it->first - prev(it)->first);
        layer += it->second;
        it++;
    }
    for (int i = 1; i <= n; ++i){
        cout << ans[i] << endl;
    }
    return 0;
}