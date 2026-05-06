#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int MAXN = 3;
constexpr int BIT= 1 << 3;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("outofplace.in", "r", stdin);
//    freopen("outofplace.out", "w", stdout);
    vector<pair<int, int>> logo(MAXN);
    for (int i = 0; i < MAXN; ++i){
        cin >> logo[i].first >> logo[i].second;
    }
    int s = 0;
    for (auto e : logo){
        s += e.first * e.second;
    }
    int len = round(sqrt(s));
    if (len * len != s){
        cout << -1;
        return 0;
    }
    for (int rotate_logo = 0; rotate_logo < BIT; ++rotate_logo){
        vector<vector<char>> grid(len, vector<char>(len, 'Z'));
        int numplace = 0;
        for (int i = 0; i < len; ++i){
            for (int j = 0; j < len; ++j){
                if (grid[i][j] != 'Z') continue;
                if (numplace > 2) goto end;
                int h = logo[numplace].first;
                int w = logo[numplace].second;
                if (rotate_logo & (1 << numplace)){
                    swap(h, w);
                }
                for (int row = i; row < i + h; ++row){
                    for (int col = j; col < j + w; ++col){
                        if (row >= len || col >= len || grid[row][col] != 'Z') goto end;
                        grid[row][col] = (char)(numplace + 'A');
                    }
                }
                numplace++;
                j = j + w - 1;
            }
        }
        cout << len << endl;
        for (int i = 0; i < len; ++i){
            for (int j = 0; j < len; ++j){
                cout << grid[i][j];
            }
            cout << endl;
        }
        return 0;
        end:;
    }
    cout << -1;
    return 0;
}