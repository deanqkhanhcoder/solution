#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 4; i <= n; i += 2)
        is_prime[i] = false;
    for (int i = 3; i * i <= n; i += 2) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    int cnt = 0;
    vector<bool> prime = sieve(31623);
    while (n--){
        int a; cin >> a;
        float x = sqrt(a);
        if ((int)x * x == a && prime[(int)x]){
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}