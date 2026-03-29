#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    vector<int> ia;
    int sumj = -1;
    for (int i = 0; i < 3; ++i){
        int j1, j2, j3; cin >> j1 >> j2 >> j3;
        if (i == 0) sumj = j1 + j2 + j3;
        if ((j1 == j2 && j2 == j3) || sumj != j1 + j2 + j3){
            cout << "NO";
            return 0;
        }
        ia.push_back(j1);
        ia.push_back(j2);
        ia.push_back(j3);
    }
    for (int i = 0; i < 3; ++i){
        if (ia[i] == ia[i + 3] && ia[i] == ia[i + 6] || ia[i] + ia[i + 3] + ia[i + 6] != sumj){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}