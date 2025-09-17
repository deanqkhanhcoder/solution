#include <iostream>
using namespace std;

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(){
     FastIO();
    int n; cin >> n;
    int cnt = 0;
    for (int i = 5; i <= n; i *= 5){
        cnt += n / i;
    }
    cout << cnt;
    return 0;
}