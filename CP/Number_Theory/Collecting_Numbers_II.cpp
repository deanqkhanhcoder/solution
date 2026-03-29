#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> l(n + 1), pos(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        pos[l[i]] = i;
    }
    int rd = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) rd++;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << rd << "\n";
            continue;
        }
        int x = l[a], y = l[b];

        // Lấy tất cả các giá trị liên quan để tính rd
        set<int> vals = {x, y};
        if (x > 1) vals.insert(x - 1);
        if (x < n) vals.insert(x + 1);
        if (y > 1) vals.insert(y - 1);
        if (y < n) vals.insert(y + 1);

        // Trước swap, giảm rd
        for (int v : vals) {
            if (v > 1 && pos[v] < pos[v - 1]) rd--;
        }

        swap(l[a], l[b]);
        swap(pos[x], pos[y]);

        // Sau swap, tăng rd
        for (int v : vals) {
            if (v > 1 && pos[v] < pos[v - 1]) rd++;
        }

        cout << rd << "\n";
    }

    return 0;
}
