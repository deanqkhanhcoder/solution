#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    set<int> dp;
    dp.insert(0);

    for(int x : a) {
        set<int> add;
        for(int s : dp) {
            add.insert(s + x);
        }
        dp.insert(add.begin(), add.end());
    }
    dp.erase(0);
    cout << dp.size() << "\n";
    for(int s : dp) cout << s << " ";
    cout << "\n";

    return 0;
}
