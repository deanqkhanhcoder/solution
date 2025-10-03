#include <bits/stdc++.h>
using namespace std;

long long maxAlternatingSum(vector<int>& a) {
    long long up = 0, down = 0;
    long long max_total = LLONG_MIN;

    for(long long x : a) {
        if(x > 0) {
            up = max(x, down + x);
            max_total = max(max_total, up);
        } else if(x < 0) {
            down =max(x, up + x);
            max_total = max(max_total, down);
        }
    }
    return max_total;
}

int main() {
    vector<int> a = {1, -2, 3, -4, 5};
    cout << "Tong lon nhat cua day con doi dau: " << maxAlternatingSum(a) << endl;
    return 0;
}
