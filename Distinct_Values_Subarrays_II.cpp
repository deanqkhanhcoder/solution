#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    unordered_map<int,int> freq;
    freq.reserve(2*n);
    freq.max_load_factor(0.7);

    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n) {
            freq[a[r]]++;
            if ((int)freq.size() > k) {
                freq[a[r]]--;
                if (freq[a[r]] == 0) freq.erase(a[r]);
                break;
            }
            r++;
        }
        ans += (r - l);
        freq[a[l]]--;
        if (freq[a[l]] == 0) freq.erase(a[l]);
    }

    cout << ans << "\n";
}
