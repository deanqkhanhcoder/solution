#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;
struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        x += FIXED_RANDOM;
        x ^= (x >> 23) ^ (x << 16);
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int,int, custom_hash> last;
    int ans = 0, left = 0;
    for (int right = 0; right < n; right++) {
        if (last.count(a[right]) && last[a[right]] >= left) {
            left = last[a[right]] + 1;
        }
        last[a[right]] = right;
        ans = max(ans, right - left + 1);
    }
    cout << ans;
}
