#include <iostream>
#include <string>
using namespace std;

int n;
string curstr = "";

void genGray(int pos, bool reverse) {
    if (pos > n) {
        cout << curstr << "\n";
        return;
    }
    if (reverse) {
        curstr.push_back('1');
        genGray(pos + 1, false);
        curstr.pop_back();

        curstr.push_back('0');
        genGray(pos + 1, true);
        curstr.pop_back();
    } else {
        curstr.push_back('0');
        genGray(pos + 1, false);
        curstr.pop_back();

        curstr.push_back('1');
        genGray(pos + 1, true);
        curstr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    genGray(1, false);
    return 0;
}