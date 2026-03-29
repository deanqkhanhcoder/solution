#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ----------------- Cách 1: Greedy thường -----------------
bool isValidGreedy(const vector<ll>& a, int k, ll limit) {
    ll curSum = 0;
    int cnt = 1; // ít nhất 1 đoạn
    for (ll x : a) {
        if (curSum + x > limit) {
            cnt++;
            curSum = x;
            if (cnt > k) return false;
        } else {
            curSum += x;
        }
    }
    return true;
}

// ----------------- Cách 2: Prefix + Binary Search -----------------
bool isValidPrefix(const vector<ll>& a, int k, ll limit) {
    int n = a.size();
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i - 1];

    int cnt = 0;
    int pos = 0; // bắt đầu từ prefix[0]
    while (pos < n) {
        ll target = pre[pos] + limit;
        // tìm r lớn nhất sao cho pre[r] <= target
        int r = upper_bound(pre.begin(), pre.end(), target) - pre.begin() - 1;
        if (r == pos) return false; // không nhảy được -> fail
        pos = r;
        cnt++;
        if (cnt > k) return false;
    }
    return cnt <= k;
}

// ----------------- Main -----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    ll l = *max_element(a.begin(), a.end());
    ll r = sum;

    // --- Greedy check ---
    ll lo = l, hi = r;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (isValidGreedy(a, k, mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << "Greedy ans  = " << lo << "\n";

    // --- Prefix check ---
    lo = l; hi = r;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (isValidPrefix(a, k, mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << "Prefix ans  = " << lo << "\n";
}
