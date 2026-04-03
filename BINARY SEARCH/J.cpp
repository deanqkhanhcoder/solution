#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int Q; cin >> Q;
    auto f = [](int x){
        return 1LL * x * x * x - 2 * x + 5; 
    };
    while (Q--){
        ll K; cin >> K;
        if (K == 0){
            cout << 0 << endl;
            continue;
        }
        int lo = 1, hi = (int)1e6;
        while (lo < hi){
            int mid = (hi + lo + 1) / 2;
            if (f(mid) <= K) lo = mid;
            else hi = mid - 1;
        }
        cout << (f(lo) == K ? lo : -1) << endl;
    }
    return 0;
}
