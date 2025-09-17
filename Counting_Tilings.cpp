#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = (int) 1e9 + 7;
int n, m;
vector<vector<pair<int,int>>> pr;

void dfs(int row, int cm, int nm, vector<pair<int,int>> &res) {
    if (row == n) {
        res.push_back({nm, 1});
        return;
    }
    if (cm & (1 << row)) {
        dfs(row + 1, cm, nm, res);
    } else {
        // vertical domino
        if (row + 1 < n && !(cm & (1 << (row + 1)))) {
            dfs(row + 2, cm, nm, res);
        }
        // horizontal domino
        dfs(row + 1, cm, nm | (1 << row), res);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    if (n > m) swap(n, m);
    int maxm; maxm = 1 << n;

    // Tiền xử lý pr
    pr.resize(maxm);
    for (int mask = 0; mask < maxm; mask++) {
        vector<pair<int,int>> res;
        dfs(0, mask, 0, res);

        // gộp các NEXTMASK trùng nhau (tăng ways)
        unordered_map<int,int> cnt;
        for (auto [nm, w] : res) {
            cnt[nm] = (cnt[nm] + w) % MOD;
        }
        for (auto &kv : cnt) {
            pr[mask].push_back(kv);
        }
    }

    // DP chạy theo cột
    vector<ll> cur(maxm, 0), nxt(maxm, 0);
    cur[0] = 1;
    for (int col = 0; col < m; col++) {
        fill(nxt.begin(), nxt.end(), 0);
        for (int mask = 0; mask < maxm; mask++) {
            if (!cur[mask]) continue;
            for (auto [nmask, cnt] : pr[mask]) {
                nxt[nmask] = ((ll)nxt[nmask] + cur[mask] * cnt) % MOD;
            }
        }
        cur.swap(nxt);
    }
    cout << cur[0];
    return 0;
}
