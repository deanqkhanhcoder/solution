#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#define lowbit(i) ((i) & (-(i)))
using namespace std;
using ll = long long;
int n;
vector<ll> BIT;
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
    vector<int> a(n + 1);
    BIT.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        int ai; cin >> ai;
        BIT[i] = ai;
        a[i] =  ai;
    }
    for (int i = 1; i <= n; ++i){
        int j = i + lowbit(i);
        if (j <= n) BIT[j] += BIT[i];
    }
    while(q--){
        int type; cin >> type;
        if (type == 1){
            int k, u; cin >> k >> u;
            int diff = u - a[k];
            update(k, diff);
            a[k] = u;
        } else {
            int l, r; cin >> l >> r;
            ll res = query(r) - query(l - 1);
            cout << res << '\n';
        }
    }
    return 0;
}