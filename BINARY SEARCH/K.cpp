#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll M, K, N; cin >> M >> K >> N;
    ll S = M * K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    ll current_sum = 0;
    int min_len = N; 
    int left = 0;
    for (int right = 0; right < N; ++right) {
        current_sum += A[right];
        while (current_sum >= S) {
            min_len = min(min_len, right - left + 1);
            current_sum -= A[left];
            left++;
        }
    }
    cout << min_len << endl;
    return 0;
}