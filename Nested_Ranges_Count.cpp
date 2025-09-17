#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ---- Fenwick Tree (BIT) cho đếm tần suất theo chỉ số 0-based ----
class Fenwick {
public:
    explicit Fenwick(int n) : n_(n), bit_(n + 1, 0) {}

    // cộng 'delta' vào vị trí idx (0-based)
    void add(int idx, int delta = 1) {
        for (++idx; idx <= n_; idx += idx & -idx) bit_[idx] += delta;
    }

    // tổng prefix từ 0..idx (0-based). Nếu idx < 0 trả về 0.
    
    int sumPrefix(int idx) const {
        if (idx < 0) return 0;
        int s = 0;
        for (++idx; idx > 0; idx -= idx & -idx) s += bit_[idx];
        return s;
    }

    // tổng trên đoạn [l, r] (0-based). Nếu l > r → 0.
    int sumRange(int l, int r) const {
        if (l > r) return 0;
        return sumPrefix(r) - sumPrefix(l - 1);
    }

private:
    int n_;
    vector<int> bit_;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // a[i] = ((l, r), idx_gốc)
    using Range = pair<pair<int,int>, int>;
    vector<Range> a(n);

    vector<int> allR; allR.reserve(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a[i] = {{l, r}, i};
        allR.push_back(r);
    }

    // --- Nén toạ độ cho r (vì r có thể tới 1e9) ---
    sort(allR.begin(), allR.end());
    allR.erase(unique(allR.begin(), allR.end()), allR.end());
    auto getId = [&](int r) {
        return int(lower_bound(allR.begin(), allR.end(), r) - allR.begin());
    };
    const int M = (int)allR.size();

    // --- Sort theo (l tăng), nếu l bằng thì (r giảm) ---
    sort(a.begin(), a.end(), [](const Range& A, const Range& B) {
        if (A.first.first != B.first.first) return A.first.first < B.first.first; // l tăng
        return A.first.second > B.first.second;                                   // r giảm
    });

    vector<int> contains(n, 0), contained(n, 0);

    // ===================== TÍNH 'contains' =====================
    // Duyệt từ phải -> trái. Khi đứng tại [l_i, r_i], những đoạn đã "thấy"
    // đều có l >= l_i (vì chúng ở bên phải sau khi sort).
    // Số đoạn bị [l_i, r_i] chứa = số r' (của các đoạn đã thấy) thoả r' <= r_i.
    {
        Fenwick bit(M); // BIT đếm theo id của r
        for (int i = n - 1; i >= 0; --i) {
            int r_id = getId(a[i].first.second);
            // số r' <= r_i chính là sumPrefix(r_id)
            contains[a[i].second] = bit.sumPrefix(r_id);
            bit.add(r_id, 1); // "thấy" thêm một đoạn có r = r_i
        }
    }

    // ===================== TÍNH 'contained' =====================
    // Duyệt từ trái -> phải. Khi đứng tại [l_i, r_i], những đoạn đã "thấy"
    // đều có l <= l_i (vì ở bên trái sau khi sort).
    // Số đoạn chứa [l_i, r_i] = số r' (đã thấy) thoả r' >= r_i.
    // Tương đương: tổng đã thấy - số r' < r_i.
    {
        Fenwick bit(M);
        for (int i = 0; i < n; ++i) {
            int r_id = getId(a[i].first.second);
            int seen = bit.sumPrefix(M - 1);          // tổng đã thấy
            int less = bit.sumPrefix(r_id - 1);       // r' < r_i
            contained[a[i].second] = seen - less;     // r' >= r_i
            bit.add(r_id, 1); // "thấy" thêm một đoạn có r = r_i
        }
    }

    // --- In theo thứ tự input gốc ---
    for (int i = 0; i < n; ++i) {
        cout << contains[i] << (i + 1 == n ? '\n' : ' ');
    }
    for (int i = 0; i < n; ++i) {
        cout << contained[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
