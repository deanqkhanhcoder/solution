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
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n; cin >> n;
    vector<int> out(n, 0);
    for (int i = 0; i < n - 1; ++i){
        int a, b; cin >> a >> b;
        a--;
        out[a]++;
    }
    
    int cnt = 0;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (out[i] == 0) {
            cnt++;
            ans = i + 1;
        }
    }
    cout << (cnt == 1 ? ans : -1);
    return 0;
}