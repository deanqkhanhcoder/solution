#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int maxl = 1, currl = 1;

    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            currl++;
        } else {
            currl = 1;
        }
        maxl = max(maxl, currl);
    }

    cout << maxl;
    return 0;
}
