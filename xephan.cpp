#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
using namespace std;
constexpr int MAX = 1000000;
int nxt[MAX + 1];
bitset<MAX + 1> has;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    memset(nxt, -1, sizeof(nxt));
    int limit = 0;
    for (int i = 0; i < n; ++i){
        int u, v; cin >> u >> v;
        nxt[u] = v;
        has[v] = 1;
        limit = max(limit, u);
    }
    vector<int> res(n);
    int curr = nxt[0];
    for (int i = 1; i < n; i += 2) {
        res[i] = curr;
        curr = nxt[curr];
    }
    for (int i = 1; i <= limit; ++i){
        if (nxt[i] != -1 && !has[i]){
            curr = i;
            break;
        }
    }
    for (int i = 0; i < n; i += 2){
        res[i] = curr;
        curr = nxt[curr];
    }
    for (int i = 0; i < n; ++i){
        cout << res[i] << ' ';
    }
    return 0;
}