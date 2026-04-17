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
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> pr = {2, 3, 5, 7};
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < (int)pr.size(); ++j){
            if (pr[j] == s[i] - '0'){
                cout << pr[j] << ' ';
                pr.erase(pr.begin() + j);
                break;
            }
        }
        if (pr.empty()) break;
    }
}