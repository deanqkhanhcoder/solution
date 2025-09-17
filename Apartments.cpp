/*
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    
    multiset<int> a, b;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        b.insert(x);
    }

    auto ita = a.begin();
    auto itb = b.begin();
    int cnt = 0;

    while (ita != a.end() && itb != b.end()) {
        if (*itb < *ita - k) ++itb;
        else if (*itb > *ita + k) ++ita;
        else {
            ++cnt;
            ++ita;
            ++itb;
        }
    }

    cout << cnt;
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int cnt = 0;

    while (i < n && j < m) {
        if (b[j] < a[i] - k) j++;
        else if (b[j] > a[i] + k) i++;
        else {
            cnt++;
            i++;
            j++;
        }
    }

    cout << cnt;
    return 0;
}
