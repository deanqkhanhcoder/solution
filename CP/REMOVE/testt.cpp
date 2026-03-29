#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("out.txt", "w", stdout);

    const int N = 1e6;

    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i < N; i++)
        cout << i << endl;

    auto end = chrono::high_resolution_clock::now();

    cerr << "Time: "
         << chrono::duration<double>(end - start).count()
         << "s\n";
}
