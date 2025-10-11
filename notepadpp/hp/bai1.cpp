#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <string>
using namespace std;
int add(char a, char b){
    return (a - '0') + (b - '0');
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n; cin >> n;
    cout << (add(n[0], n[1]) == add(n[2], n[3]) ? "YES" : "NO");
    return 0;
}