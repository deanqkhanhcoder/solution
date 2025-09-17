#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <climits>
#include <deque>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b; cin >> n >> a >> b;
    ll prefix[n + 1];
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }
    ll ans = LLONG_MIN;
    deque<int> dq;
    for (int r = a; r <= n; ++r){
        int l = r - a;
        while (!dq.empty() && prefix[dq.back()] >= prefix[l])
            dq.pop_back();
        dq.push_back(l);
        while (dq.front() < r - b)
            dq.pop_front();
        ans = max(ans, prefix[r] - prefix[dq.front()]);
    }
    cout << ans;
    return 0;
}