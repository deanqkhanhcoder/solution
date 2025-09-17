#include <iostream>
using namespace std;

bool ispali(int a[], int left, int right) {
    if (left >= right) return true;
    if (a[left] != a[right]) return false;
    return ispali(a, left + 1, right - 1);
}

int main(){
    int n;
    cin >> n;
    int a[1005];
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (ispali(a, 0, n - 1)){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}