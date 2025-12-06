#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); ++i)
        if (isdigit(s[i])) cnt++;
    cout << cnt;
    return 0;
}