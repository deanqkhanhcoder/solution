#include <iostream>
#include <vector>
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
        if (x > 1 && pos[x] < pos[x - 1]) rd--;
        cout << "rd 1 = " << rd << "\n"; 
        if (y < n && pos[y + 1] < pos[y]) rd--;
        cout << "rd 2 = " << rd << "\n"; 
        if (x != y - 1){
            if (y > 1 && pos[y] < pos[y - 1]) rd--;
            cout << "rd 3 = " << rd << "\n"; 
            if (x < n && pos[x + 1] < pos[x]) rd--;
            cout << "rd 4 = " << rd << "\n"; 
        }
        swap(l[a], l[b]);
        swap(pos[x], pos[y]);
        if (x > 1 && pos[x] < pos[x - 1]) rd++;
        cout << "rd 1 = " << rd << "\n"; 
        if (y < n && pos[y + 1] < pos[y]) rd++;
        cout << "rd 2 = " << rd << "\n"; 
        if (x != y - 1){
            if (y > 1 && pos[y] < pos[y - 1]) rd++; 
            cout << "rd 3 = " << rd << "\n"; 
            if (x < n && pos[x + 1] < pos[x]) rd++;
            cout << "rd 4 = " << rd << "\n"; 
        }


        cout << rd << "\n";
    }

    return 0;
}
