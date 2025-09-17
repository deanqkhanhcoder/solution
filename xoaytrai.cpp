#include <iostream>
using namespace std;

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    FastIO();
    int n, k; cin >> n >> k;
    int start = (n - k % n + n) % n;
    int res[n];
    for (int i = start; i < n + start; ++i){
        cin >> res[i % n];
    }
    for (int i = 0; i < n; ++i){
        cout << res[i] << ' ';
    }
    return 0;
}