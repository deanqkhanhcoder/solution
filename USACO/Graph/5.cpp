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
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, k; cin >> n >> k;
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
    vector<int> p1(n + 1);
    for (int i = 1; i <= n; ++i){
        int pos = i;
        if (a1 <= pos && pos <= a2){
            pos = a1 + a2 - pos;
        }
        if (b1 <= pos && pos <= b2){
            pos = b1 + b2 - pos;
        }
        p1[i] = pos;
    }
    vector<bool> visited(n + 1, false);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i){
        if (visited[i]) continue;
        vector<int> cycle;
        cycle.reserve(n); 
        int cur = i;
        while (!visited[cur]){
            visited[cur] = true;
            cycle.push_back(cur);
            cur = p1[cur];
        }
        int len = (int)cycle.size();
        for (int j = 0; j < len; ++j){
            int next = (j + k) % len;
            ans[cycle[j]] = cycle[next];
        }
    }
    vector<int> res(n + 1);
    for (int i = 1; i <= n; ++i){
        res[ans[i]] = i; 
    }
    for (int i = 1; i <= n; ++i){
        cout << res[i] << endl;
    }
    return 0;
}