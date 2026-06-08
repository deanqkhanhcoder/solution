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
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    pair<int, int> b;
    cin >> b.first >> b.second;
    pair<int, int> s;
    cin >> s.first >> s.second;
    pair<int, int> g;
    cin >> g.first >> g.second;
    pair<int, int> p;
    cin >> p.first >> p.second;
    int win_p = p.second - p.first;
    int win_g = g.second - g.first + win_p;
    int win_s = s.second - s.first + win_g;
    cout << win_s << endl;
    cout << win_g << endl;
    cout << win_p << endl;
}