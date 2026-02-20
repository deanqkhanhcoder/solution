#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
// constexpr int MAXS = 1000;
using namespace std;
int pos;
vector<vector<int>> grid;
int cell(char &a, char &b){
    int col = a - 'A';
    int row = b - '1';
    return grid[row][col];
}
int eval(string &s);

int solve(string &s){
    int len = s.size();
    string name;
    while(pos < len && isalpha(s[pos])){
        name.push_back(s[pos]);
        pos++;
    }
    pos++; // (
    vector<int> val;
    while (true){
        val.push_back(eval(s));
        if (s[pos] == ',') pos++;
        else break;
    }
    pos++; // )
    if (name == "SUM"){
        int res = 0;
        for (int x : val) res += x;
        return res;
    } else if (name == "MAX"){
        int res = *max_element(val.begin(), val.end());
        return res;
    }
    return 0;
}

int eval(string &s){
    if (isupper(s[pos]) && isdigit(s[pos + 1])){
        int res = cell(s[pos], s[pos + 1]);
        pos += 2;
        return res;
    }
    return solve(s);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n; cin >> m >> n;
    grid.resize(9, vector<int>(26));
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            cin >> grid[i][j];
        }
    }
    int q; cin >> q;
    while (q--){
        string s; cin >> s;
        pos = 0;
        cout << eval(s) << '\n';
    }
}
