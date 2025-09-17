#include <iostream>
#include <vector>
using namespace std;

void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 4; i <= n; i += 2) // Đánh dấu số chẵn > 2 là không nguyên tố
        is_prime[i] = false;

    for (int i = 3; i * i <= n; i += 2) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                is_prime[j] = false; // Bỏ qua số chẵn
            }
        }
    }

    cout << 2 << " ";
    for (int i = 3; i <= n; i += 2) {
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
