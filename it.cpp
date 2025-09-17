#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << &(*it) << " ";
    }
    // Output: 10 20 30 40 50
    return 0;
}
