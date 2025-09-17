#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> a(n);
    for (auto &x : a) cin >> x;
    int freq[26] = {0};
    vector<pair<char, int>> res;

    for (int i = 0; i < n; i++) {
        char ch = a[i];
        if (freq[ch - 'a'] == 0) {
            res.push_back({ch, 1});
        } else {
            for (auto& p : res) {
                if (p.first == ch) {
                    p.second++;
                    break;
                }
            }
        }
        freq[ch - 'a']++;
    }

    cout << res.size() << '\n';
    for (auto p : res) {
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}
