#include <iostream>
using namespace std;

void both(int a[], int i, int n) {
    if (i == n) {
        cout << endl;
        return;
    }
    cout << a[i] << ' ';
    both(a, i + 1, n);
    cout << a[i] << ' ';
}

int main() {
    int n;
    cin >> n;
    int a[1005];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    both(a, 0, n);
    return 0;
}
