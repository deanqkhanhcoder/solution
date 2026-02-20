#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc để lưu thông tin một cặp
struct PairData {
    long long sum;
    int i;
    int j;
};

int n;
long long d;
vector<long long> a;
vector<PairData> all_pairs;
bool used[2005]; // Đánh dấu xem học sinh thứ i đã được ghép cặp chưa

// Hàm so sánh để sắp xếp theo đúng yêu cầu trong ảnh
bool comparePairs(const PairData& x, const PairData& y) {
    if (x.sum != y.sum) {
        return x.sum < y.sum; // Ưu tiên 1: Tổng nhỏ đến lớn
    }
    if (x.i != y.i) {
        return x.i < y.i;     // Ưu tiên 2: i nhỏ đến lớn
    }
    return x.j > y.j;         // Ưu tiên 3: j lớn đến nhỏ
}

int main() {
    // Tối ưu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("PAIR.INP", "r")) {
        freopen("PAIR.INP", "r", stdin);
        freopen("PAIR.OUT", "w", stdout);
    }

    cin >> n >> d;
    a.resize(n + 1); // Dùng chỉ số từ 1 cho khớp đề bài
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // Bước 1 trong ảnh: Sắp xếp mảng a (thực ra không bắt buộc phải sort a nếu dùng cách này, 
    // nhưng sort a giúp i, j có ý nghĩa về độ lớn giá trị hơn)
    sort(a.begin() + 1, a.end());

    // Bước 2: Xây dựng danh sách L lưu trữ các bộ (sum, i, j)
    // Dự trữ bộ nhớ để vector không phải resize nhiều lần
    all_pairs.reserve(n * (n - 1) / 2);
    
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            all_pairs.push_back({a[i] + a[j], i, j});
        }
    }

    // Sắp xếp danh sách L: O(N^2 log(N^2)) = O(N^2 log N)
    sort(all_pairs.begin(), all_pairs.end(), comparePairs);

    // Bước 3: Dùng 2 con trỏ trên danh sách cặp để tìm kết quả
    int max_cnt = 0;
    int m = all_pairs.size();
    
    // --- TRIỂN KHAI LẠI BƯỚC 3 ĐỂ CHÍNH XÁC VÀ DỄ HIỂU HƠN ---
    // Do d rất nhỏ, ta có thể duyệt qua từng giá trị tổng S có thể làm mốc "bắt đầu"
    // Ta lấy các cặp có tổng thuộc [all_pairs[i].sum, all_pairs[i].sum + d]
    
    // Để tối ưu, ta chỉ cần duyệt tuyến tính một lần.
    // Ta dùng logic: Với mỗi "cửa sổ" hợp lệ trên danh sách all_pairs, ta reset mảng đánh dấu và chọn tham lam.
    // Lưu ý: Việc reset mảng used tốn O(N), nếu làm liên tục sẽ thành O(N^3).
    // Cần cẩn thận chỗ này. 
    
    // CÁCH TỐI ƯU NHẤT CHO BƯỚC 3 (O(N^2)):
    // Ta chỉ xét các đoạn [L, R] trong all_pairs mà tổng chênh nhau không quá d.
    // Do danh sách đã sort, các phần tử này nằm liên tiếp.
    
    // Ta sẽ dùng kỹ thuật đánh dấu theo phiên (version) để không phải memset lại mảng used
    vector<int> visited(n + 1, 0);
    int version = 0; 
    
    int right = 0;
    for (int left = 0; left < m; ) {
        // Xác định vùng có tổng bằng nhau (hoặc chênh lệch <= d nếu muốn gộp)
        // Nhưng cách an toàn nhất theo đề bài (d=0, d=1) là:
        // Xét mốc tổng S = all_pairs[left].sum.
        // Mở rộng right đến khi all_pairs[right].sum > S + d
        
        long long current_min_sum = all_pairs[left].sum;
        
        // Tìm right xa nhất thỏa mãn
        while (right < m && all_pairs[right].sum <= current_min_sum + d) {
            right++;
        }
        
        // Đoạn [left, right - 1] chứa tất cả các cặp có tổng trong [S, S+d]
        // Ta thực hiện tham lam trên đoạn này
        version++; // Tăng phiên làm việc mới
        int cnt = 0;
        
        for (int k = left; k < right; k++) {
            int u = all_pairs[k].i;
            int v = all_pairs[k].j;
            
            // Nếu u và v chưa được dùng trong phiên này
            if (visited[u] != version && visited[v] != version) {
                visited[u] = version;
                visited[v] = version;
                cnt++;
            }
        }
        
        max_cnt = max(max_cnt, cnt);
        
        // Quan trọng: Tăng left lên. 
        // Để tránh O(N^3), ta không tăng left từng đơn vị, mà ta nhảy đến giá trị tổng tiếp theo.
        // Vì nếu chỉ dịch left 1 chút mà vẫn chung một vùng tổng S thì kết quả tham lam sẽ kém đi (do mất cặp đầu tiên ưu tiên nhất).
        
        // Tìm vị trí tiếp theo có tổng khác hẳn
        int next_left = left + 1;
        while (next_left < m && all_pairs[next_left].sum == all_pairs[left].sum) {
            next_left++;
        }
        left = next_left;
    }

    cout << max_cnt;
    return 0;
}