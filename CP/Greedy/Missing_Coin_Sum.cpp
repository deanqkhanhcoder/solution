#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    ll current_sum = 0;
    for (int i = 0; i < n; i++) {
        if (coins[i] > current_sum + 1) {
            break;
        }
        current_sum += coins[i];
    }
    cout << current_sum + 1;
    return 0;
}