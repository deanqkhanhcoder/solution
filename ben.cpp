#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int N = 10'000'000;
const int ROUNDS = 50;

int a[N];
volatile long long checksum = 0; // chống optimizer xoá code

void warmup() {
    for (int i = 0; i < N; i++)
        a[i] = i;
}

long long bench_memset() {
    auto start = high_resolution_clock::now();
    for (int r = 0; r < ROUNDS; r++) {
        memset(a, 0, sizeof(a));
        checksum += a[r]; // chống tối ưu
    }
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

long long bench_fill() {
    auto start = high_resolution_clock::now();
    for (int r = 0; r < ROUNDS; r++) {
        fill(a, a + N, 0);
        checksum += a[r];
    }
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    warmup(); // tránh page fault bias

    long long t1 = bench_memset();
    long long t2 = bench_fill();

    cout << "memset total: " << t1 << " ms\n";
    cout << "fill total:   " << t2 << " ms\n";
    cout << "checksum: " << checksum << "\n";
}