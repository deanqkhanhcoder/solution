#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    int n; cin >> n;
    vector<int> a(n);
    vector<int> temp(n);
    for (int &x : a) cin >> x;
    auto solve = [&](auto &&self, int l, int r){
        if (l >= r) return;
        int mid = (l + r) / 2;
        self(self, l, mid);
        self(self, mid + 1, r);
        int i = l;
        int j = mid + 1;
        int k = l;
        while (i <= mid && j <= r){
            if (a[i] <= a[j]) temp[k++] = a[i++];
            else temp[k++] = a[j++];
        }
        while (i <= mid){
            temp[k++] = a[i++];
        }
        while (j <= r){
            temp[k++] = a[j++];
        }
        for (int x = l; x <= r; ++x) a[x] = temp[x];
        return;
    };
    solve(solve, 0, n - 1);
    for (int x : a) cout << x << ' ';
    cout << endl;
    return 0;
}