#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int MAXN = 1e7 + 5;
int a1[MAXN], a2[MAXN]; // Dữ liệu mảng cho 2 cách
int n, k;

// FastIO bằng fread
namespace FastIO {
    const int BSIZE = 1 << 20;
    char buffer[BSIZE];
    int pos = 0, len = 0;

    inline char nextChar() {
        if (pos == len) {
            pos = 0;
            len = fread(buffer, 1, BSIZE, stdin);
            if (len == 0) return EOF;
        }
        return buffer[pos++];
    }

    inline void readInt(int &x) {
        x = 0;
        char c;
        bool neg = false;
        do { c = nextChar(); } while (c != '-' && (c < '0' || c > '9'));
        if (c == '-') { neg = true; c = nextChar(); }
        while (c >= '0' && c <= '9') {
            x = x * 10 + (c - '0');
            c = nextChar();
        }
        if (neg) x = -x;
    }
}

void rotate_modulo(int* a, int n, int k) {
    k %= n;
    int* temp = new int[n];
    for (int i = 0; i < n; ++i) {
        temp[(i + k) % n] = a[i];
    }
    memcpy(a, temp, n * sizeof(int));
    delete[] temp;
}

void rotate_memmove(int* a, int n, int k) {
    k %= n;
    int* tmp = new int[k];
    memcpy(tmp, a + n - k, k * sizeof(int));             // copy đoạn cuối
    memmove(a + k, a, (n - k) * sizeof(int));            // dời đoạn đầu ra sau
    memcpy(a, tmp, k * sizeof(int));                     // gán đoạn cuối về đầu
    delete[] tmp;
}

int main() {
    freopen("input.txt", "r", stdin);
    FastIO::readInt(n);
    FastIO::readInt(k);
    for (int i = 0; i < n; ++i) {
        FastIO::readInt(a1[i]);
        a2[i] = a1[i]; // copy sang mảng thứ hai để test cách 2
    }

    cout << fixed << setprecision(3);

    // Cách 1: dùng modulo
    auto start1 = high_resolution_clock::now();
    rotate_modulo(a1, n, k);
    auto end1 = high_resolution_clock::now();
    cout << "[CACH 1] modulo:\t\t\t" << duration_cast<milliseconds>(end1 - start1).count() << " ms\n";

    // Cách 2: dùng memmove + memcpy
    auto start2 = high_resolution_clock::now();
    rotate_memmove(a2, n, k);
    auto end2 = high_resolution_clock::now();
    cout << "[CACH 2] memcpy + memmove:\t" << duration_cast<milliseconds>(end2 - start2).count() << " ms\n";

    return 0;
}
