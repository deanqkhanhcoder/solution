#include <iostream>
#include <vector>
using namespace std;
const int OFFSET = 1000;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> freq(2001, 0);
    vector<pair<int, int>> res;

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (freq[x + OFFSET] == 0) {
            res.push_back({x, 1});
        } else {
            for (size_t j = 0; j < res.size(); ++j) {
                if (res[j].first == x) {
                    res[j].second++;
                    break;
                }
            }
        }
        freq[x + OFFSET]++;
    }

    for (auto p : res) {
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}
