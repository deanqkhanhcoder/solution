#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
// pair<int, int> operator-(pair<int, int> &a, pair<int, int> &b){
//     return {b.first - a.first, b.second - a.second};
// }
// ll dist(pair<int, int> &a, pair<int, int> &b){
//     pair<int, int> ba = b - a;
//     return (ll)ba.first*ba.first + ba.second*ba.second;
// }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < 4; ++i){
        int x, y; cin >> x >> y;
        pos[x].push_back(y);
    }
    if (pos.size() != 2){
        cout << -1;
        return 0;
    }
    vector<int> fi = pos.begin()->second;
    vector<int> se = next(pos.begin())->second;
    sort(fi.begin(), fi.end());
    sort(se.begin(), se.end());
    if (fi[0] == se[0] && fi[1] == se[1]){
        int x1 = pos.begin()->first;
        int x2 = next(pos.begin())->first;
        if (x1 < x2) swap(x1, x2);
        if (abs(x2 - x1) == abs(fi[1] - fi[0])){
            cout << (ll)abs(x2 - x1) * abs(x2 - x1);
            return 0;
        }
    } else {
        cout << -1;
        return 0;
    }
}