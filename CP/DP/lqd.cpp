#include <bits/stdc++.h>
using namespace std;

struct Pair {
    long long cost, value;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long M;
    cin >> n >> M;

    vector<vector<pair<long long, long long>>> a(4, vector<pair<long long, long long>>(n));
    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < n; ++i)
            cin >> a[k][i].first >> a[k][i].second; // (cost, value)
    }

    vector<Pair> A, B;

    // nhóm A: chip + màn hình
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            A.push_back({a[0][i].first + a[1][j].first,
                         a[0][i].second + a[1][j].second});

    // nhóm B: bo mạch + vỏ máy
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            B.push_back({a[2][i].first + a[3][j].first,
                         a[2][i].second + a[3][j].second});

    sort(B.begin(), B.end(), [](const Pair &x, const Pair &y) {
        return x.cost < y.cost;
    });

    // Chuẩn hóa: với mỗi cost, giữ value max
    for (int i = 1; i < (int)B.size(); ++i)
        B[i].value = max(B[i].value, B[i - 1].value);

    long long ans = 0;
    for (auto &p : A) {
        if (p.cost > M) continue;
        long long remain = M - p.cost;
        int l = 0, r = (int)B.size() - 1, pos = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (B[mid].cost <= remain) {
                pos = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        if (pos != -1)
            ans = max(ans, p.value + B[pos].value);
    }

    cout << ans;
}
