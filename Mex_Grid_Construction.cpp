#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<bool> used(2 * n, false); 
            for (int k = 0; k < j; k++) {
                used[a[i][k]] = true;
            }
            for (int k = 0; k < i; k++) {
                used[a[k][j]] = true;
            }
            int mex = 0;
            while (used[mex]) mex++;
            a[i][j] = mex;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << (j + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
