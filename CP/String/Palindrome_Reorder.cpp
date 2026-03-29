#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a; cin >> a;
    int n = a.size();
    vector<int> v(26, 0);
    for (char c : a) v[c - 'A']++;
    int cnt = 0, idx = -1;
    for (int i = 0; i < 26; ++i) {
        if (v[i] % 2 == 1) {
            idx = i;
            cnt++;
        }
    }
    if ((n % 2 == 0 && cnt > 0) || (n % 2 == 1 && cnt != 1)) {
        cout << "NO SOLUTION";
        return 0;
    }
    for (int i = 0; i < 26; ++i) {
        cout << string(v[i] / 2, 'A' + i);
    }
    if (idx != -1){
        cout << string(v[idx] % 2, 'A' + idx);
    }
    for (int i = 25; i >= 0; --i) {
        cout << string(v[i] / 2, 'A' + i);
    }
    return 0;
}