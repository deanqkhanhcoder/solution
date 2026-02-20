#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;
using ll = long long;
constexpr ll NEG = (ll)-1e16;
constexpr int MSIZE = (int)1e5;
void solve(){
    int n; cin >> n;
    int k = n / 2;
    vector<ll> a(n + 2);
    vector<int> L(n + 2);
    vector<int> R(n + 2);
    bitset<MSIZE + 2> visited;
    priority_queue<pair<ll, int>> pq;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        L[i] = i - 1;
        R[i] = i + 1;
        pq.push({a[i], i});
    }
    a[0] = a[n + 1] = NEG;
    L[0] = 0; R[0] = 1;
    L[n + 1] = n; R[n + 1] = n + 1;
    ll ans = 0;
    int cnt = 0;
    while (cnt < k){
        ll cur = pq.top().first;
        int index = pq.top().second;
        pq.pop();
        if (visited[index]) continue;
        ans += cur;
        cnt++;
        int left = L[index];
        int right = R[index];
        visited[left] = visited[right] = 1;
        a[index] = a[left] + a[right] - a[index];
        L[index] = L[left];
        R[index] = R[right];
        R[L[index]] = L[R[index]] = index;
        pq.push({a[index], index});
    }
    cout << ans << '\n';
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}