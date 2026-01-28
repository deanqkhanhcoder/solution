#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll t, f, v;
};

// Map lưu trữ Pareto Frontier: Key = Fuel, Value = Value
// Đảm bảo tính chất: Fuel tăng -> Value phải tăng
map<ll, ll> pareto_map;

// Hàm thêm một trạng thái (f, v) vào tập Pareto
void add_option(ll f, ll v) {
    // 1. Kiểm tra xem (f, v) có bị ai đó tốt hơn "đè" không?
    // Tìm phần tử có Fuel <= f. Vì map sắp xếp theo key tăng dần,
    // upper_bound(f) trả về phần tử đầu tiên > f. 
    // lùi lại 1 bước (prev) sẽ là phần tử <= f có Fuel lớn nhất.
    auto it = pareto_map.upper_bound(f);
    if (it != pareto_map.begin()) {
        auto prev_it = prev(it);
        // Nếu tồn tại một trạng thái tốn ít xăng hơn (hoặc bằng) 
        // mà giá trị >= v, thì (f, v) là vô dụng.
        if (prev_it->second >= v) return;
    }

    // 2. (f, v) là một trạng thái tiềm năng. Thêm nó vào map.
    // Trước khi thêm, cần xóa những thằng tệ hơn nó (Fuel >= f nhưng Value <= v).
    // Bắt đầu từ vị trí it (là phần tử đầu tiên > f).
    while (it != pareto_map.end()) {
        if (it->second <= v) {
            it = pareto_map.erase(it); // Xóa và lấy iterator tiếp theo
        } else {
            // Do tính chất đơn điệu, nếu gặp 1 thằng V > v thì các thằng sau cũng V > v (hoặc F lớn hơn hẳn)
            // Tuy nhiên với map Pareto chuẩn, ta chỉ xóa những thằng F >= f và V <= v.
            // Vì F trong map luôn tăng, nên ta chỉ cần check V.
            // Nhưng cẩn thận: map Pareto của ta là F tăng -> V tăng.
            // Nếu it->second > v thì thằng này KHÔNG bị (f,v) đè, và các thằng sau cũng thế.
            break; 
        }
    }
    
    pareto_map[f] = v;
}

// Hàm truy vấn: Tìm max V với nhiên liệu <= limit_f
ll query(ll limit_f) {
    auto it = pareto_map.upper_bound(limit_f);
    if (it == pareto_map.begin()) return -1e18; // Không tìm thấy
    return prev(it)->second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R;
    ll M, U;
    if (!(cin >> R >> M >> U)) return 0;

    vector<ll> T(R), F(R), V(R);
    for (int i = 0; i < R; i++)
        cin >> T[i] >> F[i] >> V[i];

    int n1 = R / 2, n2 = R - n1;
    vector<Node> A, B;

    // Sinh tập A
    for (int mask = 0; mask < (1 << n1); mask++) {
        ll t = 0, f = 0, v = 0;
        for (int i = 0; i < n1; i++) {
            if (mask & (1 << i)) {
                t += T[i]; f += F[i]; v += V[i];
            }
        }
        if (t <= M && f <= U) A.push_back({t, f, v});
    }

    // Sinh tập B
    for (int mask = 0; mask < (1 << n2); mask++) {
        ll t = 0, f = 0, v = 0;
        for (int i = 0; i < n2; i++) {
            if (mask & (1 << i)) {
                t += T[n1 + i]; f += F[n1 + i]; v += V[n1 + i];
            }
        }
        if (t <= M && f <= U) B.push_back({t, f, v});
    }

    // --- LOGIC CHÍNH ---

    // 1. Sort A giảm dần theo T (để nới lỏng ràng buộc thời gian cho B)
    sort(A.begin(), A.end(), [](const Node &a, const Node &b) {
        return a.t > b.t;
    });

    // 2. Sort B tăng dần theo T (để dần dần đẩy vào map)
    sort(B.begin(), B.end(), [](const Node &a, const Node &b) {
        return a.t < b.t;
    });

    ll ans = 0;
    int ptr_b = 0; // Con trỏ duyệt mảng B
    int size_b = B.size();

    // Khởi tạo map với giá trị rỗng (0 fuel, 0 value) để luôn có kết quả nền
    // Tuy nhiên B đã có sẵn phần tử {0,0,0} do sinh mask=0, nên không cần add thủ công.
    // Nhưng để an toàn với hàm query, ta nên đảm bảo map không rỗng hoặc handle kỹ.
    // Ở đây B chắc chắn có {0,0,0}, nên khi ptr_b chạy, map sẽ có dữ liệu.

    for (auto &a : A) {
        ll rem_t = M - a.t;
        ll rem_f = U - a.f;

        // Đẩy tất cả các phần tử B thỏa mãn điều kiện thời gian vào Map Pareto
        while (ptr_b < size_b && B[ptr_b].t <= rem_t) {
            add_option(B[ptr_b].f, B[ptr_b].v);
            ptr_b++;
        }

        // Truy vấn trong Map: Tìm thằng có F <= rem_f có V lớn nhất
        ll val = query(rem_f);
        if (val != -1e18) {
            ans = max(ans, a.v + val);
        }
    }

    cout << ans << "\n";
    return 0;
}