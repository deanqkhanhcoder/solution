// debug_find.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = LLONG_MIN / 4;

// ------------------ reference DP O(n*k) for correctness (works only for small n,k) ------------------
ll solve_dp_ref(const vector<ll>& a, int k) {
    int n = (int)a.size();
    const ll NEGINF = NEG;
    vector<vector<ll>> keep(n+1, vector<ll>(k+1, NEGINF));
    vector<vector<ll>> rem(n+1, vector<ll>(k+1, NEGINF));
    keep[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            // extend keep from keep or rem (and add a[i-1])
            if (keep[i-1][j] != NEGINF) keep[i][j] = max(keep[i][j], keep[i-1][j] + a[i-1]);
            if (rem[i-1][j] != NEGINF)  keep[i][j] = max(keep[i][j], rem[i-1][j] + a[i-1]);
            if (j > 0) {
                if (rem[i-1][j] != NEGINF) rem[i][j] = max(rem[i][j], rem[i-1][j]);
                if (keep[i-1][j-1] != NEGINF) rem[i][j] = max(rem[i][j], keep[i-1][j-1]);
            }
        }
    }
    ll ans = NEGINF;
    for (int j = 0; j <= k; ++j) {
        ans = max(ans, keep[n][j]);
        ans = max(ans, rem[n][j]);
    }
    return ans;
}

// ------------------ segtree + PQ solution (attempt) ------------------
struct Node {
    int l=-1, r=-1;
    ll sum=0;
    ll pref=NEG; int lpref=-1, rpref=-1;
    ll suf=NEG;  int lsuf=-1, rsuf=-1;
    ll best=NEG; int lbest=-1, rbest=-1;
};
Node mergeNode(const Node &L, const Node &R){
    if (L.l == -1) return R;
    if (R.l == -1) return L;
    Node res;
    res.l = L.l; res.r = R.r;
    res.sum = L.sum + R.sum;
    // pref
    if (L.pref >= L.sum + R.pref) {
        res.pref = L.pref; res.lpref = L.lpref; res.rpref = L.rpref;
    } else {
        res.pref = L.sum + R.pref; res.lpref = L.l; res.rpref = R.rpref;
    }
    // suf
    if (R.suf >= R.sum + L.suf) {
        res.suf = R.suf; res.lsuf = R.lsuf; res.rsuf = R.rsuf;
    } else {
        res.suf = R.sum + L.suf; res.lsuf = L.lsuf; res.rsuf = R.r;
    }
    // best
    res.best = L.best; res.lbest = L.lbest; res.rbest = L.rbest;
    if (R.best > res.best) { res.best = R.best; res.lbest = R.lbest; res.rbest = R.rbest; }
    ll cross = L.suf + R.pref;
    if (cross > res.best) { res.best = cross; res.lbest = L.lsuf; res.rbest = R.rpref; }
    return res;
}

struct SegTree {
    int n=0, N=1;
    vector<Node> st;
    void init(int _n) { n=_n; N=1; while(N<n) N<<=1; st.assign(2*N, Node()); }
    void build(const vector<ll>& b) {
        for (int i=0;i<n;i++){
            Node nd; nd.l = nd.r = i; nd.sum = b[i];
            nd.pref = nd.suf = nd.best = b[i];
            nd.lpref = nd.rpref = nd.lsuf = nd.rsuf = nd.lbest = nd.rbest = i;
            st[N+i] = nd;
        }
        for (int i=n;i<N;i++) st[N+i] = Node();
        for (int p=N-1;p>=1;--p) st[p] = mergeNode(st[2*p], st[2*p+1]);
    }
    Node query(int l, int r) {
        if (l>r) return Node();
        l+=N; r+=N;
        Node left, right; bool hasLeft=false, hasRight=false;
        while (l<=r) {
            if (l&1) { if(!hasLeft){ left = st[l]; hasLeft=true; } else left = mergeNode(left, st[l]); l++; }
            if (!(r&1)) { if(!hasRight){ right = st[r]; hasRight=true; } else right = mergeNode(st[r], right); r--; }
            l>>=1; r>>=1;
        }
        if (!hasLeft && !hasRight) return Node();
        if (!hasLeft) return right;
        if (!hasRight) return left;
        return mergeNode(left, right);
    }
};

struct Item { ll best; int L,R,bl,br; };
struct Cmp { bool operator()(Item const& a, Item const& b) const { return a.best < b.best; } };

ll solve_segtree(const vector<ll>& a, int k) {
    int n = (int)a.size();
    if (n==0) return 0;
    vector<ll> b(n);
    ll total = 0;
    for (int i=0;i<n;i++){ b[i] = -a[i]; total += a[i]; }
    SegTree st; st.init(n); st.build(b);
    priority_queue<Item, vector<Item>, Cmp> pq;
    Node full = st.query(0,n-1);
    if (full.best > 0) pq.push({full.best, 0, n-1, full.lbest, full.rbest});
    ll sumSelected = 0; int cnt=0;
    while (!pq.empty() && cnt < k) {
        Item it = pq.top(); pq.pop();
        if (it.best <= 0) break;
        sumSelected += it.best;
        cnt++;
        int L=it.L, R=it.R, bl=it.bl, br=it.br;
        if (L <= bl-1) {
            Node ln = st.query(L, bl-1);
            if (ln.best > 0) pq.push({ln.best, L, bl-1, ln.lbest, ln.rbest});
        }
        if (br+1 <= R) {
            Node rn = st.query(br+1, R);
            if (rn.best > 0) pq.push({rn.best, br+1, R, rn.lbest, rn.rbest});
        }
    }
    return total + sumSelected;
}

// -------------------------------- random test harness --------------------------------
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // RANDOM SEARCH MODE
    std::mt19937_64 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int iter = 0; iter < 200000; ++iter) {
        int n = rng() % 12 + 1;        // small
        int k = rng() % (n+1);
        vector<ll> a(n);
        for (int i=0;i<n;i++) {
            // mix of small and larger ranges
            if ((rng() & 7) == 0) a[i] = (ll)( (long long)(rng() % 1000000000) - 500000000 );
            else a[i] = (ll)( (long long)(rng() % 50) - 25 );
        }
        ll ref = solve_dp_ref(a, k);
        ll seg = solve_segtree(a, k);
        if (ref != seg) {
            cerr << "FOUND MISMATCH on iter " << iter << "\n";
            cerr << "n=" << n << " k=" << k << "\n";
            cerr << "a: ";
            for (auto v: a) cerr << v << " ";
            cerr << "\nREF=" << ref << " SEG=" << seg << "\n";
            cout << "MISMATCH TEST\n";
            cout << n << " " << k << "\n";
            for (auto v: a) cout << v << ( &v==&a.back()? "\n":" ");
            return 0;
        }
    }
    cout << "NO MISMATCH FOUND\n";
    return 0;
}
