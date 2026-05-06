#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    deque<int> dq;
    int maxest = -1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        dq.push_back(x);
        maxest = max(maxest, x);
    }
    vector<pair<int, int>> history;
    while (dq.front() != maxest) {
        int A = dq.front(); dq.pop_front();
        int B = dq.front(); dq.pop_front();
        history.push_back({A, B});
        if (A > B) {
            dq.push_front(A);
            dq.push_back(B);
        } else {
            dq.push_front(B);
            dq.push_back(A);
        }
    }
    int cnt = (int)history.size();
    dq.pop_front();
    int q; cin >> q;
    while (q--) {
        ll k; cin >> k;
        if (k <= cnt) {
            cout << history[k - 1].first << " " << history[k - 1].second << "\n";
        } else {
            int idx = (k - cnt - 1) % (n - 1);
            cout << maxest << " " << dq[idx] << "\n";
        }
    }
    return 0;
}