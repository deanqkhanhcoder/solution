#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    int chan = 0, le = 0;
    
    while (cin >> x) {
        if (x % 2 == 0) chan++;
        else le++;
    }

    if (chan > le) cout << "CHAN\n";
    else if (le > chan) cout << "LE\n";
    else cout << "CHANLE\n";

    return 0;
}
