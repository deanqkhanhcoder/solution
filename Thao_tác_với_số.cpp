#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
     if (n >= m) {
        cout << n - m;
        return 0;
    }
    vector<int> ans(2*m + 1, -1);
    queue<int> q;
    q.push(n);
    ans[n] = 0;
    while (!q.empty()){
        int x = q.front();
        q.pop();
        if (x == m){
            cout << ans[m];
            return 0;
        }
        if (x * 2 <= 2 * m && ans[x * 2] == -1){
            ans[x * 2] = ans[x] + 1;
            q.push(x * 2);
        }
        if (x - 1 >= 1 && ans[x - 1] == - 1){
            ans[x - 1] = ans[x] + 1;
            q.push(x - 1);
        }
    }
    return 0;
}