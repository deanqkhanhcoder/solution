#include <iostream>
using namespace std;

/*
  Mapping:
   - We use a 9x9 visited array and đánh dấu viền (0 và 8) là visited để tránh kiểm tra ngoài biên.
   - Lưới thực tế 7x7 nằm trong [1..7] x [1..7].
   - Start = (1,1) (upper-left), Target = (7,1) (lower-left) -- theo đề bài CSES Grid Paths.
   - Input: chuỗi độ dài 48 gồm các ký tự 'L','R','U','D','?'
*/

string s;
bool vis[9][9];
int ans = 0;

// directions: D, U, L, R (tương ứng với đề bài)
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char dirs[4] = {'D','U','L','R'};

int dfs(int r, int c, int step) {
    // nếu đã thực hiện đủ 48 bước: kiểm tra có ở target không
    if (step == 48) return (r == 7 && c == 1) ? 1 : 0;
    // nếu đến target trước khi đủ bước => không hợp lệ
    if (r == 7 && c == 1) return 0;

    // pruning chia vùng: nếu trái & phải bị chặn nhưng trên & dưới đều mở -> bị tách vùng
    if (vis[r][c-1] && vis[r][c+1] && !vis[r-1][c] && !vis[r+1][c]) return 0;
    // tương tự: trên & dưới bị chặn nhưng trái & phải mở -> tách vùng
    if (vis[r-1][c] && vis[r+1][c] && !vis[r][c-1] && !vis[r][c+1]) return 0;

    vis[r][c] = true;
    int total = 0;

    if (s[step] != '?') {
        // đi theo chỉ dẫn bắt buộc nếu hợp lệ
        char want = s[step];
        for (int k = 0; k < 4; ++k) {
            if (dirs[k] == want) {
                int nr = r + dr[k], nc = c + dc[k];
                if (!vis[nr][nc]) total += dfs(nr, nc, step+1);
                break;
            }
        }
    } else {
        // thử 4 hướng (cũng có thể áp dụng thứ tự heuristics nếu muốn)
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (!vis[nr][nc]) total += dfs(nr, nc, step+1);
        }
    }

    vis[r][c] = false;
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> s)) return 0;
    // chuẩn hoá độ dài (đề cho 48)
    // tạo viền visited = true để tránh kiểm tra bounds
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) vis[i][j] = false;
    }
    for (int i = 0; i < 9; ++i) {
        vis[0][i] = vis[8][i] = vis[i][0] = vis[i][8] = true;
    }
    // bắt đầu từ (1,1)
    cout << dfs(1,1,0) << '\n';
    return 0;
}
