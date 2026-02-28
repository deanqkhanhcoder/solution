#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    string s; cin >> s;
    bool ok = true;
    for (int i = 1; i < n; ++i){
        if (s[i] != s[i - 1]){
            ok = false;
        }
    }
    if (ok){
        cout << 0;
        return 0;
    }
    int l = 0, r = n - 1;
    while (l < r){
        if (s[l] != s[r]){
            cout << n;
            return 0;
        }
        l++;
        r--;
    }
    cout << n - 1;
    return 0;
}