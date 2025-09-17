#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> freq(26, 0);
    for (char ch : s) freq[ch - 'A']++;
    if (*max_element(freq.begin(), freq.end()) > (n + 1) / 2) {
        cout << -1 << '\n';
        return 0;
    }
    string res;
    res.reserve(n);
    char last = '\0';
    for (int step = 0; step < n; ++step) {
        bool placed = false;
        int rem = n - step - 1;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) continue;
            char ch = char('A' + i);
            if (last != '\0' && ch == last) continue;
            freq[i]--;
            int max_rem = *max_element(freq.begin(), freq.end());
            if (max_rem <= (rem + 1) / 2) {
                res.push_back(ch);
                last = ch;
                placed = true;
                break;
            } else {
                freq[i]++;
            }
        }
        if (!placed) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << res << '\n';
    return 0;
}
