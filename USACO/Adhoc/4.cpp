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
constexpr int MAX_C = 9;
constexpr int INF = (int)1e9;
constexpr int NEG = (int)-1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    int n; cin >> n;
    vector<int> left(MAX_C + 1, INF);
    vector<int> right(MAX_C + 1, NEG);
    vector<int> top(MAX_C + 1, INF);
    vector<int> bot(MAX_C + 1, NEG);
    vector<vector<int>> art(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            char c; cin >> c;
            int color = c - '0';
            art[i][j] = color;
            if (color != 0){
                left[color] = min(left[color], j);
                right[color] = max(right[color], j);
                top[color] = min(top[color], i);
                bot[color] = max(bot[color], i);
            }
        }
    }
    vector<int> in_dergee(MAX_C + 1, 0);
    for (int color = 1; color <= MAX_C; ++color){
        // cerr << "left[" << color << "] = " << left[color] << endl;
        // cerr << "right[" << color << "] = " << right[color] << endl;
        // cerr << "top[" << color << "] = " << top[color] << endl;
        // cerr << "bot[" << color << "] = " << bot[color] << endl;
        if (left[color] == INF){
            in_dergee[color] = -1;
            continue;
        }
        for (int i = top[color]; i <= bot[color]; ++i){
            for (int j = left[color]; j <= right[color]; ++j){
                if (art[i][j] != color){
                   in_dergee[art[i][j]] = 1; 
                }
            }   
        }
    }
    int ans = 0;
    for (int color = 1; color <= MAX_C; ++color){
        // cerr << "in_dergee[" << color << "] : " << in_dergee[color] << endl; 
        ans += (!in_dergee[color]);
    }
    cout << ans;
}