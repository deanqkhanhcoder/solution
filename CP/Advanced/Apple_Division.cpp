#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    int n; 
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int leftSize = n / 2;
    int rightSize = n - leftSize;
    vector<ll> leftSums;
    for (int mask = 0; mask < (1 << leftSize); mask++) {
        ll sum = 0;
        for (int i = 0; i < leftSize; i++) {
            if (mask & (1 << i)) sum += a[i];
        }
        leftSums.push_back(sum);
    }

    vector<ll> rightSums;
    for (int mask = 0; mask < (1 << rightSize); mask++) {
        ll sum = 0;
        for (int i = 0; i < rightSize; i++) {
            if (mask & (1 << i)) sum += a[leftSize + i];
        }
        rightSums.push_back(sum);
    }

    sort(rightSums.begin(), rightSums.end());

    ll total = 0;
    for (auto w : a) total += w;

    ll ans = total;
    for (auto x : leftSums) {
        ll target = total / 2 - x;

        auto it = lower_bound(rightSums.begin(), rightSums.end(), target);

        if (it != rightSums.end()) {
            ll currSum = x + *it;
            ll diff = abs(2*currSum - total);
            if (diff < ans) ans = diff;
        }
        if (it != rightSums.begin()) {
            --it;
            ll currSum = x + *it;
            long long diff = abs(2*currSum - total);
            if (diff < ans) ans = diff;
        }
    }

    cout << ans;

    return 0;
}
