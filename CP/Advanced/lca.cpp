#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005; // đủ cho n <= 1e5
const int LOG = 20;

int n, q;
vector<int> g[MAXN];
int up[LOG][MAXN];
int depthArr[MAXN];
int tin[MAXN], tout[MAXN], timerD = 0;
int N;
ll a[MAXN];
int ROOT = 1;

void dfs(int v, int p){
    up[0][v] = p;
    depthArr[v] = (p == -1 ? 0 : depthArr[p] + 1);
    tin[v] = ++timerD;
    for (int to: g[v]){
        if (to == p) continue;
        dfs(to, v);
    }
    tout[v] = timerD;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v){
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int k = LOG-1; k >= 0; --k){
        int p = up[k][u];
        if (p != -1 && !is_anc(p, v)) u = p;
    }
    return up[0][u];
}

int kth_ancestor(int u, int k){
    for (int i = 0; i < LOG; ++i){
        if (k & (1<<i)){
            u = up[i][u];
            if (u == -1) return -1;
        }
    }
    return u;
}

int lca_rooted(int u, int v, int R){
    int c1 = lca(u, v);
    int c2 = lca(u, R);
    int c3 = lca(v, R);
    int best = c1;
    if (depthArr[c2] > depthArr[best]) best = c2;
    if (depthArr[c3] > depthArr[best]) best = c3;
    return best;
}

// Fenwick supporting range add and prefix sum
struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(){}
    Fenwick(int _n){init(_n);}
    void init(int _n){ n=_n; bit.assign(n+1,0);}
    void add(int i, ll delta){
        for (; i <= n; i += i & -i) bit[i] += delta;
    }
    ll sum(int i){
        ll r = 0;
        for (; i > 0; i -= i & -i) r += bit[i];
        return r;
    }
} B1, B2;

void range_add(int l, int r, ll val){
    if (l > r) return;
    // update B1,B2 as usual
    B1.add(l, val);
    B1.add(r+1, -val);
    B2.add(l, val*(l-1));
    B2.add(r+1, -val*r);
}
ll prefix_sum(int x){
    if (x <= 0) return 0;
    ll s1 = B1.sum(x);
    ll s2 = B2.sum(x);
    return s1 * x - s2;
}
ll range_sum(int l, int r){
    if (l > r) return 0;
    return prefix_sum(r) - prefix_sum(l-1);
}

// update all nodes in "subtree of v" w.r.t current ROOT by +x
void update_subtree_wrt_root(int v, ll x){
    if (v == ROOT){
        // whole tree
        range_add(1, N, x);
        return;
    }
    if (!is_anc(v, ROOT)){
        // subtree is normal
        range_add(tin[v], tout[v], x);
        return;
    } else {
        // v is ancestor of ROOT, subtree = whole tree \ subtree(child)
        int k = depthArr[ROOT] - depthArr[v] - 1;
        int child = kth_ancestor(ROOT, k);
        // add to whole tree
        range_add(1, N, x);
        // subtract child subtree
        range_add(tin[child], tout[child], -x);
    }
}

ll query_subtree_wrt_root(int v){
    if (v == ROOT){
        return range_sum(1, N);
    }
    if (!is_anc(v, ROOT)){
        return range_sum(tin[v], tout[v]);
    } else {
        int k = depthArr[ROOT] - depthArr[v] - 1;
        int child = kth_ancestor(ROOT, k);
        return range_sum(1, N) - range_sum(tin[child], tout[child]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    N = n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // dfs from 1 as base root
    for (int i = 1; i <= n; ++i) for (int k=0;k<LOG;++k) up[k][i] = -1;
    timerD = 0;
    dfs(1, -1);
    // build up table
    for (int k = 1; k < LOG; ++k){
        for (int v = 1; v <= n; ++v){
            if (up[k-1][v] == -1) up[k][v] = -1;
            else up[k][v] = up[k-1][ up[k-1][v] ];
        }
    }
    // init Fenwick
    B1.init(n+5);
    B2.init(n+5);
    // assign initial values to positions tin[i]
    for (int i = 1; i <= n; ++i){
        range_add(tin[i], tin[i], a[i]);
    }
    ROOT = 1;

    while (q--){
        int type; cin >> type;
        if (type == 1){
            int v; cin >> v;
            ROOT = v;
        } else if (type == 2){
            int u, v; ll x; cin >> u >> v >> x;
            int L = lca_rooted(u, v, ROOT);
            update_subtree_wrt_root(L, x);
        } else if (type == 3){
            int v; cin >> v;
            ll ans = query_subtree_wrt_root(v);
            cout << ans << '\n';
        }
    }
    return 0;
}
