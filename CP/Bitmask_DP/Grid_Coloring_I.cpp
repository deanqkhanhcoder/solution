#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char colors[4] = {'A', 'B', 'C', 'D'};
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<string> ans(n, string(m, '.'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (char c : colors) {
                if (c != grid[i][j] && 
                    (j == 0 || c != ans[i][j-1]) &&
                    (i == 0 || c != ans[i-1][j])) {
                    ans[i][j] = c;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << "\n";
    return 0;
}
