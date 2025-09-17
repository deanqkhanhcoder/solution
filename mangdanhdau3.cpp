#include <iostream>
using namespace std;

const int MAX = 1e6 + 1;
int freq[MAX] = {0};
int A[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        freq[A[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        if (freq[A[i]] > 0) {
            cout << A[i] << ' ' << freq[A[i]] << '\n';
            freq[A[i]] = 0; // Đánh dấu đã in
        }
    }

    return 0;
}
