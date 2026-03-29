#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int cnt[1001] = {0};
    for (int i = 0; i < n; ++ i){
        int a; cin >> a;
        cnt[a] = 1;
    }

    int prev = -1;
    int dif = INT_MAX;

    for (int i = 0; i < 1001; ++i){
        if (cnt[i]) {
            if (prev != -1){
                dif = min(dif, i - prev);
            }
            prev = i;
        }
    }
        cout << dif;
    return 0;
}