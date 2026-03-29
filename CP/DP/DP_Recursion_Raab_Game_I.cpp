#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, a, b; 
        cin >> n >> a >> b;
        int c = n - a - b;
        if (c < 0 || ((a == 0) ^ (b == 0))) {
            cout << "NO\n";
            continue;
        }
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);
        vector<int> q;
        int m = a + b;
        if (m == 0) {
            q = arr;
        } else {
            vector<int> M(arr.begin(), arr.begin() + m);
            rotate(M.begin(), M.begin() + a, M.end());
            q.insert(q.end(), M.begin(), M.end());
            q.insert(q.end(), arr.begin() + m, arr.end());
        }

        cout << "YES\n";
        for (int x : arr) cout << x << ' ';
        cout << "\n";
        for (int x : q) cout << x << ' ';
        cout << "\n";
    }
}
