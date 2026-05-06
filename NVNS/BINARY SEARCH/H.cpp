#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    vector<int> edge(n);
    for (int i = 0; i < n; ++i){
        int e; cin >> e;
        edge[i] = e * e;
    }
    sort(all(edge));
    // for (int &e : edge) cout << e << " ";
    // cout << endl;
    ll nhon = 0, vuong = 0, tu = 0;
    for (int i = 0; i < n - 2; ++i){
        for (int j = i + 1; j < n - 1; ++j){
            int a = edge[i];
            int b = edge[j];
            int c = a + b + 2 * (int)sqrt(a) * (int)sqrt(b);
            auto start = edge.begin() + j + 1;
            auto limit = lower_bound(start, edge.end(), c);
            if (limit == start) continue;
            int x = a + b;
            auto it1 = lower_bound(start, limit, x);
            auto it2 = upper_bound(start, limit, x);
            vuong += it2 - it1;
            // if (a == 100 && b == 144){
            //     cout << (it1 == edge.end()) << " " << (it2 == edge.end()) << endl;
            //     cout << it1 - edge.begin() - j - 1 << endl;
            // }    
            if (it1 != start) nhon += it1 - edge.begin() - j - 1;
            if (it2 != limit) tu += limit - it2;
            // cerr << "a = " << a << ", b = " << b << ", c = " << c << " , x = " << x << ", nhon = " << nhon << " vuong = " << vuong << " tu : " << tu << endl;
        }
    }
    cout << nhon << " " << vuong << " " << tu;
    return 0;
}