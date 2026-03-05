#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
using ll = long long;
constexpr int MAXN = (int)1e5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<ll> a(n + 2);
        priority_queue<pair<ll, int>> pq;
        vector<int> L(n + 2), R(n + 2);
        a[0] = a[n + 1] = -1e16;
        L[0] = 0, L[n + 1] = n;
        R[0] = 1; R[n + 1] = n + 1;
            for (int i = 1; i <= n; ++i){
            cin >> a[i];
            L[i] = i - 1;
            R[i] = i + 1;
            pq.push({a[i], i});
        }
        bitset<MAXN + 2> visited;
        int k = n / 2;
        int cnt = 0;
        ll ans = 0;
        while (cnt < k){
            ll val = pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            if (visited[pos]) continue;
            ans += val;
            cnt++;
            visited[L[pos]] = visited[R[pos]] = 1;
            a[pos] = a[L[pos]] + a[R[pos]] - a[pos];
            L[pos] = L[L[pos]];
            R[pos] = R[R[pos]];
            L[R[pos]] = pos;
            R[L[pos]] = pos;
            pq.push({a[pos], pos});
        }
        cout << ans << '\n';
    }
    return 0;
}