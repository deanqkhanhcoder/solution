#include <iostream>
using namespace std;

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(){
    int n; cin >> n;
    int res[1005];
    int size = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (size == 0 || res[size - 1] != x) {
            res[size++] = x;
        }
    }
    for (int i = 0; i < size; ++i) {
        cout << res[i] << " ";
    }
    return 0;
}
