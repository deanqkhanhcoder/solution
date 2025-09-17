#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll curr = a[0], best = a[0];
    for (int i = 1; i < n; i++) {
        curr = max(a[i], curr + a[i]); 
        best = max(best, curr);
    }
    cout << best;
}
