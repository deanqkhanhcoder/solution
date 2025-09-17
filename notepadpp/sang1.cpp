#include <iostream>
#include <vector>
using namespace std;

void sieve(int n) {
    vector<bool> is_prime(n + 1, true);  // Khởi tạo mảng đánh dấu
    is_prime[0] = is_prime[1] = false;   // 0 và 1 không phải số nguyên tố

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false; // Đánh dấu các bội số của i là không nguyên tố
        }
    }

    // In ra các số nguyên tố
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i])
            cout << i << " ";
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    sieve(n);
    return 0;
}
