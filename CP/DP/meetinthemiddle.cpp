#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int &e : a){
        cin >> e;
        sum += e;
    }
    if (sum % 2 != 0){
        cout << "NO";
        return 0;
    }
    int t = sum / 2;
    vector<char> dp(t + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i){
        for (int j = t; j >= a[i]; --j){
            if (dp[j - a[i]]) dp[j] = 1;
        }
    }
    if (dp[t]){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}