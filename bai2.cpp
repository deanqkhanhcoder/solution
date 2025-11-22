#include <bits/stdc++.h>
using namespace std;

long long gcd3(long long a, long long b, long long c) {
    return std::gcd(a, std::gcd(b, c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int P;
    if (!(cin >> N >> P)) return 0;
    long long A, B;
    int R;
    cin >> A >> B >> R;

    int N0 = (int)(N % P);
    A %= P;
    B %= P;
    int C = (int)((A + B) % P);

    // (tuỳ chọn) kiểm tra điều kiện cần bằng gcd
    long long g = gcd3(P, A, B);
    if (( (R - N0) % g + g ) % g != 0) {
        cout << -1;
        return 0;
    }

    const int INF = -1;
    vector<int> dist(P, INF);
    queue<int> q;

    auto try_push = [&](int x, int d) {
        if (dist[x] == INF) {
            dist[x] = d;
            q.push(x);
        }
    };

    // Khởi tạo sau bước đầu tiên (1 thao tác)
    int s1 = (N0 + (int)A) % P;
    int s2 = (N0 + (int)B) % P;
    int s3 = (N0 + C) % P;

    if (s1 == R || s2 == R || s3 == R) {
        cout << 1;
        return 0;
    }

    try_push(s1, 1);
    try_push(s2, 1);
    try_push(s3, 1);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == R) break;

        int v1 = (u + (int)A) % P;
        int v2 = (u + (int)B) % P;
        int v3 = (u + C) % P;

        if (v1 == R || v2 == R || v3 == R) {
            cout << dist[u] + 1;
            return 0;
        }

        try_push(v1, dist[u] + 1);
        try_push(v2, dist[u] + 1);
        try_push(v3, dist[u] + 1);
    }

    cout << dist[R];
    return 0;
}
