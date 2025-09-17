#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a;
int n;
vector<int> cnt;

void genstr() {
    if ((int)a.size() == n) {
        cout << a << "\n";
        return;
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] > 0) {
            cnt[i]--;
            a.push_back(char('a' + i));
            genstr();
            a.pop_back();
            cnt[i]++;
        }
    }
}

long long factorial(int x) {
    long long res = 1;
    for (int i = 2; i <= x; ++i) res *= i;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    n = s.size();
    cnt.assign(26, 0);
    for (char c : s) cnt[c - 'a']++;
    long long ans = factorial(n);
    for (int x : cnt) ans /= factorial(x);
    cout << ans << "\n";
    genstr();
}
