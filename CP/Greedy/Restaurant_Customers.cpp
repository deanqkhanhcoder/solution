#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arrive(n), leave(n);
    for (int i = 0; i < n; i++) cin >> arrive[i] >> leave[i];

    sort(arrive.begin(), arrive.end());
    sort(leave.begin(), leave.end());

    int curr = 0, maxcus = 0;
    int i = 0, j = 0;

    while (i < n) {
        if (arrive[i] < leave[j]) {
            curr++;
            maxcus = max(maxcus, curr);
            i++;
        } else {
            curr--;
            j++;
        }
    }

    cout << maxcus << '\n';
    return 0;
}
