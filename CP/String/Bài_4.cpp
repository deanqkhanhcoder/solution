#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("inline") 
#include <iostream> 
#include <vector> 
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    string ans; ans.reserve(t);
    while (t--) {
        int n, k; cin >> n >> k;
        if (k % 2 == 0) {
            ans.push_back('0');
            for (int x; n--; ) cin >> x;
            continue;
        }
        bool ok1 = false, ok2 = false;
        unordered_set<int> v; 
        v.reserve(n * 2);
        v.max_load_factor(0.7);
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            if (a % 2 == 0) ok1 = true;
            else ok2 = true;
            v.insert(a);
        }
        if (!ok1 || !ok2) {
            ans.push_back('0');
            continue;
        }
        bool ok = false;
        for (int e : v) {
            if ((e % 2 == 0) && v.count(k - e)) {
                ok = true; break;
            }
        }
        ans.push_back(ok ? '1' : '0');
    }
    cout << ans;
}

