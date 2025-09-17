#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    unordered_map<long long,int> last; // lưu vị trí đã thấy
    long long ans = 0;
    int l = 0;

    for (int r = 0; r < n; r++) {
        if (last.count(a[r])) {
            // Đã gặp rồi thì bỏ qua, không cộng vào ans
            continue;
        }
        // chưa gặp, xử lý như bài gốc
        ans += (r - l + 1);
        last[a[r]] = r;
    }

    cout << ans << "\n";
    return 0;
}