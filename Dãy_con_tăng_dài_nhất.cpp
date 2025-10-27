#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> lis; 
    lis.reserve(n);

    for (int x : a) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }

    cout << (int)lis.size() << '\n';
    return 0;
}
