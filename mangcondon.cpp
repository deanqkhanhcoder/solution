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
    int a[1001] = {0};
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        if (i == 0){
            a[i] = x;
        } else {
            a[i] = a[i - 1] + x;
        }
        cout << a[i] << ' ';
    }
}