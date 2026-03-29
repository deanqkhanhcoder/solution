#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n], B[n-1];
    for (int i = 0; i < n; ++i) cin >> A[i];
    int res = A[0];
    for (int i = 0; i < n - 1; ++i){
        cin >> B[i];
        if (B[i] == 1)
            res += A[i + 1];
        else if (B[i] == 2)
            res -= A[i + 1];
    }
    cout << res << endl;
    return 0;
}
