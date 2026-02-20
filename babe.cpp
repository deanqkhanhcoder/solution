#include <bits/stdc++.h>
using namespace std;

int x = 0;

void dfs(int d) {
    if (d == 0) return;
    x++;
    cout << "vao dfs(" << d << "), x = " << x << '\n';
    dfs(d - 1);
    cout << "ra dfs(" << d << "), x = " << x << '\n';
    x--;
}

int main() {
    dfs(3);
}