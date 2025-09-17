#include <iostream>
#include <numeric>
using namespace std;

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    FastIO();
    int n, k; cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int sum = accumulate(a + 1, a + k + 1, 0);
    cout << sum << ' ';
    for (int i = 1; i + k <= n; ++i){
        sum = sum - a[i] + a[i + k];
        cout << sum << ' ';
    }
    return 0;
}