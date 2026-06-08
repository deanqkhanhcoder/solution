#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout); 
    /*
    block 1 : s(1, 1) .. s(1, n);
    block 2 : s(2 , 2) .. s(2, n);
    block l : s(l, l) ... s(l, n);
    block l có n - l + 1 phần tử;
    số lượng phần tử của k khối đầu tiên dc tính bằng công thức 
            sigma_i = 1 - > k (n - i + 1)
            = k * n - (k - 1) * k / 2;
    ta có s(l, r) = P[r] - P[l - 1];
    B[l] sigma_r = l -> n (s(l, r)) = sigma_r = l -> n (P[r] - P[l - 1]) <=> B[l] = simga_r = l -> n (P[r]) - (n - l + 1) * P[l - 1];
    gọi PP[i] = sigma_j = 1 -> i (P[j])
    -> B[l] = PP[n] - PP[l - 1] - (n - l + 1) * P[l - 1];
    gọi SB[i] = sigma_j = 1 -> i (B[j]);
    cách giải
    tìm dãy block từ 1 đến k KHÔNG chưa x, có nghĩa là tính k sao cho f(k) <= X; tính SB[k];
    phần còn thiếu ở block k + 1;
    số phần từ phần còn thiếu rem = X - f(k);
    => l = k + 1, r = l + rem - 1;
    S = PP[r] - PP[l - 1] * (r - l + 1) * P[l - 1];
    */
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<int> P(n + 1);
    P[0] = 0;
    for (int i = 1; i <= n; ++i) P[i] = P[i - 1] + a[i - 1];
    vector<ll> PP(n + 1);
    PP[0] = 0;
    for (int i = 1; i <= n; ++i) PP[i] = PP[i - 1] + P[i];
    vector<ll> B(n + 1);
    vector<ll> BB(n + 1);
    B[0] = BB[0] = 0;
    for (int l = 1; l <= n; ++l){
        B[l] = PP[n] - PP[l - 1] - 1LL * (n - l + 1) * P[l - 1];
        BB[l] = BB[l - 1] + B[l];
    }
    auto get_block = [&](ll idx) -> pair<int, ll>{
        auto cnt_block = [&](int k) -> ll{
            return 1LL * k * n - 1LL * k * (k - 1) / 2;
        };
        int lo = 0, hi = n;
        while (lo < hi){
            int mid = (hi + lo + 1) / 2;
            if (cnt_block(mid) <= idx) lo = mid;
            else hi = mid - 1;
        }
        return {lo, cnt_block(lo)};
    };
    auto solve = [&](ll idx) -> ll{
        pair<int, ll> q = get_block(idx);
        int k = q.first;
        ll ans = BB[k];
        int add = idx - q.second;
        if (add > 0) {
            int l = k + 1;
            int r = l + add - 1;
            ll S_add = (PP[r] - PP[l - 1]) - 1LL * (r - l + 1) * P[l - 1];
            ans += S_add;
        }
        return ans;
    };
    int q; cin >> q;
    while(q--){
        ll l, r; cin >> l >> r;
        cout << solve(r) - solve(l - 1) << endl;
    }
    return 0;
}