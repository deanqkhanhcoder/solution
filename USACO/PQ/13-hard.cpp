#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;
constexpr ll INF = 4e18; // Giới hạn đủ lớn cho tổng cặp số long long

// Hàm tính lũy thừa nhanh (base^exp) % MOD
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Hàm đếm số lượng cặp (i, j) với i < j sao cho a[i] + a[j] <= mid
// Sử dụng kỹ thuật 2 con trỏ, giới hạn đếm tối đa là target để tránh tràn số/tốn thời gian thừa
ll count_pairs(const vector<ll>& a, ll mid, ll target) {
    ll count = 0;
    int n = a.size();
    int j = n - 1;
    for (int i = 0; i < n; ++i) {
        while (j > i && a[i] + a[j] > mid) {
            j--;
        }
        if (j <= i) break;
        count += (j - i);
        if (count >= target) return count; // Đủ số lượng rồi thì dừng sớm
    }
    return count;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll ans = 0;

    // Vòng lặp mô phỏng n - 1 bước
    for (int step = 0; step < n - 1; ++step) {
        int m = a.size();
        ll shift = a[0];

        // 1. Cộng dồn đóng góp của phần tử nhỏ nhất hiện tại
        ll contribution = (shift % MOD) * power(2, n - 1 - step) % MOD;
        ans = (ans + contribution) % MOD;

        // 2. Tịnh tiến mảng về gốc 0
        for (int i = 0; i < m; ++i) {
            a[i] -= shift;
        }

        // 3. Giới hạn độ dài mảng (Mấu chốt cho bản Hard)
        // Số lượng phần tử thực tế cần giữ lại giảm cực kỳ nhanh.
        // Ta chỉ cần lấy ra tối đa m - 1 phần tử nhỏ nhất, nhưng vì mảng "phẳng hóa",
        // ta không bao giờ cần vượt quá khoảng 60 phần tử lớn nếu m lớn hơn.
        int target_size = m - 1;
        int max_keep = min(target_size, 60); 
        if (m > max_keep + 1) {
            a.resize(max_keep + 1);
            m = a.size();
        }

        // 4. Chặt nhị phân tìm giá trị ngưỡng X sao cho có đúng (target_size) tổng cặp <= X
        ll low = a[0] + a[1];
        ll high = a[m - 2] + a[m - 1];
        ll border = high;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (count_pairs(a, mid, target_size) >= target_size) {
                border = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // 5. Thu thập các tổng cặp nhỏ hơn hoặc bằng giá trị ngưỡng
        vector<ll> next_a;
        next_a.reserve(target_size);

        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                ll sum = a[i] + a[j];
                if (sum < border) {
                    next_a.push_back(sum);
                }
            }
        }

        // Điền nốt các phần tử bằng chính `border` cho đủ số lượng target_size
        while ((int)next_a.size() < target_size) {
            next_a.push_back(border);
        }

        // Sắp xếp lại mảng mới chuẩn bị cho bước tiếp theo
        sort(next_a.begin(), next_a.end());
        a = move(next_a);
    }

    // Phần tử cuối cùng còn lại
    ans = (ans + (a[0] % MOD)) % MOD;
    cout << ans << "\n";
}

int main() {
    // Tối ưu hóa I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}