#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
using namespace std;

int countDiv(int x) {
    int cnt = 0;
    for(int i = 1; i*i <= x; i++) {
        if(x % i == 0) {
            cnt++;
            if(i != x/i) cnt++;
        }
    }
    return cnt;
}

int main() {
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        cout << countDiv(x) << "\n";
    }
}
