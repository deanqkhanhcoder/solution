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
    // code here
    int n; cin >> n;
    vector<int> visited(n, false);
    vector<int> a(n);
    vector<int> b(n);
    for (int &e : a){
        cin >> e;
        e--;
    }
    for (int &e : b){
        cin >> e;
        e--;
    }
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; ++i){
        while (j < n && visited[a[j]]) j++;
        if (a[j] == b[i]){
            j++;
        } else {
            ans++;
            visited[b[i]] = true;
        }
    }
    cout << ans;
    return 0;
}