#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    vector<pair<char,int>> a;
    char c = '.';
    int d = 0;
    a.reserve(n / 2);
    for (int i = 0; i < n; ++i){
        if (isdigit(s[i])){
            d = d * 10 + (s[i] - '0');
        } else {
            if (c != '.'){
                if (c != 'H' && c != 'O' && c != 'N' && c != 'C'){
                    d = 0;
                    c = s[i];
                    continue;
                }
                if (d == 0) a.push_back({c, 1});
                else a.push_back({c, d});
                d = 0;
            }
            c = s[i];
        }  
    }

    if (c != '.'){
        if (c == 'H' || c == 'O' || c == 'N' || c == 'C'){
            if (d == 0) a.push_back({c, 1});
            else a.push_back({c, d});
        }
    }

    ll ans = 0;
    for (auto &e : a){
        if (e.first == 'H') ans += e.second;
        else if (e.first == 'O') ans += e.second * 16;
        else if (e.first == 'N') ans += e.second * 14;
        else if (e.first == 'C') ans += e.second * 12;
    }
    cout << ans;
    return 0;
}
