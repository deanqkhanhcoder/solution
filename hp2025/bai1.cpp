#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = (int)s.size();
    int sum = 0;
    string res;
    for (int i = n - 1; i >= 0; --i){
        if (isdigit(s[i])) sum += s[i] - '0';
        else res.push_back(s[i]);
    }
    cout << sum << "\n";
    if (res.empty()){
        cout << -1;
        return 0;
    }
    cout << res;
    return 0;
}