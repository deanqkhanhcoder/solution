// Dynamic Connectivity (offline) - Segment Tree on Time + DSU with Rollback
// Input format:
// n q
// For i = 1..q:
//   t u v
//   t = 1 -> add edge (u, v)
//   t = 2 -> remove edge (u, v)
//   t = 3 -> query if u and v are connected
//
// Output: For every query (t=3) print "YES" or "NO" in order.
// Complexity: O((n + q) log q) (amortized) with small constant factors.

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;

struct Edge {
    int u, v;
    Edge() {}
    Edge(int _u, int _v) : u(_u), v(_v) {}
};

// DSU with rollback
struct DSURollback {
    int n;
    vector<int> parent;
    vector<int> sz;
    // stack of changes: when we change parent[x] or sz[y], we push a record to rollback
    struct Change {
        int x_parent;
        int x;
        int y_sz;
        int y;
    };
    vector<Change> changes;
    int components;

    DSURollback() : n(0), components(0) {}

    DSURollback(int n_) { init(n_); }

    void init(int n_) {
        n = n_;
        parent.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            sz[i] = 1;
        }
        changes.clear();
        components = n;
    }

    int find(int x) {
        while (parent[x] != x) x = parent[x];
        return x;
    }

    // union by size, record changes to rollback
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            // push a dummy change so rollback count matches pushes (optional)
            changes.push_back({-1, -1, -1, -1});
            return false;
        }
        if (sz[a] < sz[b]) swap(a, b);
        // now a is bigger
        // record change: parent[b] will be a, sz[a] increases
        changes.push_back({parent[b], b, sz[a], a});
        parent[b] = a;
        sz[a] += sz[b];
        --components;
        return true;
    }

    // rollback last k operations (pop k changes)
    void rollback(int k = 1) {
        while (k-- > 0 && !changes.empty()) {
            Change ch = changes.back();
            changes.pop_back();
            if (ch.x == -1 && ch.y == -1) {
                // dummy, nothing changed
                continue;
            }
            // revert parent and sz
            parent[ch.x] = ch.x_parent;
            sz[ch.y] = ch.y_sz;
            ++components;
        }
    }

    // snapshot current changes stack size
    int snapshot() const {
        return (int)changes.size();
    }

    // rollback to a snapshot
    void rollbackTo(int snap) {
        int cur = (int)changes.size();
        int toRollback = cur - snap;
        rollback(toRollback);
    }
};

// Segment tree over time storing edges active in each node's interval
struct SegTreeOnTime {
    int n; // number of time points (queries)
    vector<vector<Edge>> tree; // tree nodes hold list of edges
    SegTreeOnTime(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        tree.assign(4 * (n + 5), {});
    }

    // add edge to interval [l, r] (1-indexed times)
    void add_interval(int node, int node_l, int node_r, int l, int r, const Edge &e) {
        if (r < node_l || node_r < l) return;
        if (l <= node_l && node_r <= r) {
            tree[node].push_back(e);
            return;
        }
        int mid = (node_l + node_r) >> 1;
        add_interval(node<<1, node_l, mid, l, r, e);
        add_interval(node<<1|1, mid+1, node_r, l, r, e);
    }
    void add_interval(int l, int r, const Edge &e) {
        if (l > r) return;
        add_interval(1, 1, n, l, r, e);
    }
};

// main solver: process segment tree and answer queries
struct DynamicConnectivitySolver {
    int n, q;
    SegTreeOnTime seg;
    DSURollback dsu;
    vector<pii> queries; // queries[i] = pair(u,v) if op i is query, else (-1,-1)
    vector<int> queryIndices; // mapping time -> index in answers if query, else -1
    vector<string> answers;

    DynamicConnectivitySolver(int _n = 0, int _q = 0) {
        init(_n, _q);
    }

    void init(int _n, int _q) {
        n = _n;
        q = _q;
        seg.init(q);
        dsu.init(n);
        queries.assign(q + 1, {-1, -1});
        queryIndices.assign(q + 1, -1);
        answers.clear();
    }

    // recursively traverse seg tree
    void solve_rec(int node, int l, int r) {
        int snap = dsu.snapshot();
        // apply all edges in this node
        for (auto &e : seg.tree[node]) {
            dsu.unite(e.u, e.v);
        }
        if (l == r) {
            if (queryIndices[l] != -1) {
                int idx = queryIndices[l];
                int u = queries[l].first;
                int v = queries[l].second;
                if (dsu.find(u) == dsu.find(v)) answers[idx] = "YES";
                else answers[idx] = "NO";
            }
        } else {
            int mid = (l + r) >> 1;
            solve_rec(node<<1, l, mid);
            solve_rec(node<<1|1, mid+1, r);
        }
        dsu.rollbackTo(snap);
    }

    // entry point after building seg tree and queries
    vector<string> run() {
        // prepare answers vector length equal to number of queries
        int totQueries = 0;
        for (int t = 1; t <= q; ++t) if (queryIndices[t] != -1) ++totQueries;
        answers.assign(totQueries, "");
        solve_rec(1, 1, q);
        return answers;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    // debug mode input from file
    // freopen("input.txt", "r", stdin);
#endif

    int n, q;
    if (!(cin >> n >> q)) {
        return 0;
    }

    // We'll read q operations. For each edge we need to know add times and remove times.
    // Map from edge -> last add time (stack of adds)
    // Because edges may be added multiple times, we treat each add-remove as a pair.
    // Format per op: t u v
    // t = 1 add, t = 2 remove, t = 3 query
    vector<tuple<int,int,int>> ops(q + 1);
    for (int i = 1; i <= q; ++i) {
        int t,u,v;
        cin >> t >> u >> v;
        if (u == v) {
            // self loops do not affect connectivity; but we'll still store as no-op
            // convert into something harmless
        }
        ops[i] = {t,u,v};
    }

    // normalize edge key (u < v)
    auto norm = [&](int a, int b)->pair<int,int>{
        if (a > b) swap(a,b);
        return {a,b};
    };

    // map edge -> stack of add times
    unordered_map<long long, vector<int>> addTimes;
    addTimes.reserve(q * 2);
    auto edgeKey = [&](int a, int b)->long long {
        if (a > b) swap(a,b);
        return ( (long long)a << 32 ) ^ (unsigned int)b;
    };

    // We will build seg tree intervals: when an add at time L and a remove at time R,
    // edge is active on [L, R-1]. If not removed till the end, active on [L, q].
    DynamicConnectivitySolver solver(n, q);

    int queryCount = 0;
    for (int i = 1; i <= q; ++i) {
        int t = get<0>(ops[i]);
        int u = get<1>(ops[i]);
        int v = get<2>(ops[i]);
        if (t == 1) {
            long long k = edgeKey(u,v);
            addTimes[k].push_back(i);
        } else if (t == 2) {
            long long k = edgeKey(u,v);
            auto it = addTimes.find(k);
            if (it == addTimes.end() || it->second.empty()) {
                // remove without prior add: ignore (no effect)
                // (alternatively you could treat as remove earliest unmatched add, but spec usually matches)
                // do nothing
            } else {
                int start = it->second.back();
                it->second.pop_back();
                // edge active on [start, i-1]
                solver.seg.add_interval(start, i-1, Edge(u,v));
            }
        } else if (t == 3) {
            // query
            solver.queries[i] = {u, v};
            solver.queryIndices[i] = queryCount++;
        } else {
            // unknown operation: ignore
        }
    }

    // any remaining adds still active until q
    for (auto &kv : addTimes) {
        auto key = kv.first;
        auto &vec = kv.second;
        while (!vec.empty()) {
            int start = vec.back();
            vec.pop_back();
            // decode key into u,v
            int u = (int)(key >> 32);
            int v = (int)(key & 0xFFFFFFFF);
            solver.seg.add_interval(start, q, Edge(u,v));
        }
    }

    // run solver and print answers in order
    auto ans = solver.run();
    for (auto &s : ans) {
        cout << s << '\n';
    }

    return 0;
}
