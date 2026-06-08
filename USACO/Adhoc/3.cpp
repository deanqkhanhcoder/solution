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
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    int ans = 0;
    for (int i = n - 1; i >= 1; --i){
        if (a[i - 1] > a[i]){
            ans = i;
            break;
        }
    }
    cout << ans;
}