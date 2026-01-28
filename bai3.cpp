#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, bool>> adj;
int m;
bool ok(int mid, int k){
    int curr = adj[0].first;
    k--;
    for (int i = 1; i < m; ++i){
        int here = adj[i].first;
        if (!adj[i].second || curr + here > mid){
            curr = here;
            k--;
            if (k < 0){
                return false;
            }
        } else {
            curr += here;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    adj.reserve(n);
    bool check = false;
    for (int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        if (b == 1){
            adj.push_back({a, check});
            check = true;
        } else {
            check = false;
        }
    }
    m = adj.size();
    int l = 0;
    int r = 0;
    int cnt = 0;
    for (int i = 0; i < m; ++i){
        l = max(l, adj[i].first);
        r += adj[i].first;
        cnt += !adj[i].second;
    }
    if (cnt > k){
        cout << -1;
        return 0;
    }
    while (l < r){
        int mid = (l + r) / 2;
        if (ok(mid, k)) r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}