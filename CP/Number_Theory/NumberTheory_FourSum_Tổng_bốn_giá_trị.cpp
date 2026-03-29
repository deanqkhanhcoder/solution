#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int &e: a) cin >> e;
    unordered_map<int, int> mp;
    for (int i = 1; i < n; ++i){
        for (int j = 0; j < i; ++j){
            int sum = a[i] + a[j];
            if (mp.count(sum)) continue;
            mp[sum] = i;
        }
    }
    for (int i = 2; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            int t = x - a[i] - a[j];
            if (mp.count(t) && mp[t] < i){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}