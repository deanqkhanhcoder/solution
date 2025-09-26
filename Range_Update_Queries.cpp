#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;
vector<ll> bit;

void update(int i, int val) {
    while (i <= n) {
        bit[i] += val;
        i += i & -i;
    }
}

ll query(int i) {
    ll sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> n >> q;
    bit.assign(n + 2, 0);
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        update(i , x);
        update(i+1, -x);
    }
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int a, b; int u;
            cin >> a >> b >> u;
            update(a, u);
            update(b+1, -u);
        } else {
            int k; cin >> k;
            cout << query(k) << "\n";
        }
    }
}