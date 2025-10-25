#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; ++i){
        int e; cin >> e;
        if (e == 100) cnt1++;
        else cnt2++;
    }
    int sum = cnt1 + cnt2 * 2;
    if (sum % 2 != 0){
        cout << "NO";
        return 0;
    }
    if (cnt2 % 2 == 0 || cnt1 > 0){
        cout << "YES";
    } else cout << "NO";
    return 0;
}