#include <bits/stdc++.h>
using namespace std;

long long gcd3(long long a, long long b, long long c) {
    return gcd(a, gcd(b, c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int P;
    cin >> N >> P;

    long long A, B;
    int R;
    cin >> A >> B >> R;

    int N0 = N % P;
    A %= P;
    B %= P;
    int C = (A + B) % P;

    // điều kiện cần: (R - N0) mod gcd(P,A,B) == 0
    long long g = gcd3(P, A, B);
    if (((R - N0) % g + g) % g != 0) {
        cout << -1;
        return 0;
    }

    vector<int> dist(P, -1);
    queue<int> q;

    // 3 trạng thái sau 1 bước đầu tiên
    int s1 = (N0 + A) % P;
    int s2 = (N0 + B) % P;
    int s3 = (N0 + C) % P;

    if (s1 == R || s2 == R || s3 == R) {
        cout << 1;
        return 0;
    }

    dist[s1] = dist[s2] = dist[s3] = 1;
    q.push(s1);
    q.push(s2);
    q.push(s3);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        int v[3] = { (u + A) % P, (u + B) % P, (u + C) % P };

        for (int nx : v) {
            if (nx == R) {
                cout << dist[u] + 1;
                return 0;
            }
            if (dist[nx] == -1) {
                dist[nx] = dist[u] + 1;
                q.push(nx);
            }
        }
    }

    cout << dist[R];
    return 0;
}
