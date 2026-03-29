#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    deque<int> dq;
    for (int i = 1; i <= n; i++) dq.push_back(i);
    while (!dq.empty()) {
        dq.push_back(dq.front());
        dq.pop_front();
        cout << dq.front() << " ";
        dq.pop_front();
    }
    return 0;
}