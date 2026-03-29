#include <iostream>
using namespace std;

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    FastIO();
    int n, m, p; cin >> n >> m >> p;
    int total = n + m;
    int res[total] = {0};
    for (int i = 0; i < n; ++i){
        if (i >= p){
            cin >> res[i + m];
        } else {
            cin >> res[i];
        }
    }
    for (int i = p; i < m + p; ++i){
        cin >> res[i];
    }
    for (int i = 0; i < total; ++i){
        cout << res[i] << ' ';
    }
    return 0;
}