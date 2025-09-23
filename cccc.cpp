#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long t, a, b;
    cin >> n >> t >> a >> b;
    
    vector<long long> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    
    sort(k.rbegin(), k.rend());
    
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + k[i - 1];
    }
    
    int best = 0;
    for (int x = 0; x <= n; x++) {
        if (n * b + x * (a - b) <= t) {
            best = x;
        } else {
            break;
        }
    }
    
    cout << prefix[best] << "\n";
    
    return 0;
}