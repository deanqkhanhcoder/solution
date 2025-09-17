#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <unordered_map>
#include <chrono>
#include <vector>
using namespace std;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        x += FIXED_RANDOM;
        x ^= (x >> 23) ^ (x << 16);
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &v : a) cin >> v;

    for (int i = 0; i <= n - 3; i++) {
        unordered_map<int, int, custom_hash> freq; // value -> index
        for (int j = i + 1; j < n; j++) {
            int need = x - a[i] - a[j];
            if (freq.count(need)) {
                // in index tăng dần, index tính từ 1
                cout << i + 1 << " " << freq[need] + 1 << " " << j + 1 << "\n";
                return 0;
            }
            freq[a[j]] = j;
        }
    }

    cout << "IMPOSSIBLE\n";
}