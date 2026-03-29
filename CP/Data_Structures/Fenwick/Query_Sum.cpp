#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int n;
vector<ll> BIT;
int lowbit(int pos){
    return pos & -pos;
}
void update(int pos, int val){
    for (; pos <= n; pos += lowbit(pos)){
        BIT[pos] += val;
    }
    return;
}
ll query(int pos){
    ll ans = 0;
    for (; pos > 0; pos -= lowbit(pos)){
        ans += BIT[pos];
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> n >> q;
    BIT.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        int ai; cin >> ai;
        BIT[i] = ai;
        // update(i, ai);
    }
    for (int i = 1; i <= n; ++i){
        int j = i + lowbit(i);
        if (j <= n) BIT[j] += BIT[i];
    } 
    while(q--){
        int type; cin >> type;
        if (type == 1){
            int pos, v; cin >> pos >> v;
            update(pos, v);
        } else {
            int u, v; cin >> u >> v;
            ll ans = query(v) - query(u - 1);
            cout << ans << '\n';
        }
    }
    return 0;
}