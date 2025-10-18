#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    set<int> p;
    p.insert(2);
    p.insert(3);
    p.insert(5);
    p.insert(7);
    int cnt = 0;
    while (n > 0){
        int d = n % 10;
        if (p.count(d)) cnt++;
        n /= 10;
    }
    cout << cnt;
    return 0;
}