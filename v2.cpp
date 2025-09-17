#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long factorial(int x) {
    long long res = 1;
    for (int i = 2; i <= x; ++i) res *= i;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;
    long long ans = factorial(n);
    for (int x : cnt) ans /= factorial(x);
    cout << ans << "\n";
    sort(s.begin(), s.end());
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}
