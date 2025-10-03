#include <iostream>
using namespace std;

bool isp(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    long long rev = 0;
    while (x > rev) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return (x == rev) || (x == rev / 10);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a[n][n];
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> a[i][j];
            if (j <= i){
                if (isp(a[i][j])) cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}