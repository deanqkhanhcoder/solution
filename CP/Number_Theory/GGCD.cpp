#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> lgcd(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        lgcd[i] = __gcd(lgcd[i - 1], a[i - 1]);
    }
    vector<int> rgcd(n + 2, 0);
    for (int i = n - 1; i >= 1; --i){
        rgcd[i] = __gcd(rgcd[i + 1], a[i + 1]);
    }
    int ans = 0;
    int maxest = 0;
    for (int i = 1; i <= n; ++i){
        maxest = __gcd(lgcd[i], rgcd[i]);
        ans = max(ans, maxest);
    }
    cout << ans;
}