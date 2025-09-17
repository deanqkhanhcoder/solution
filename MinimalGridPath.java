import java.util.*;

public class MinimalGridPath {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); // đọc newline thừa
        String[] grid = new String[n];
        for (int i = 0; i < n; i++) {
            grid[i] = sc.nextLine();
        }

        StringBuilder ans = new StringBuilder();
        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{0, 0});
        boolean[][] visited = new boolean[n][n];
        visited[0][0] = true;

        for (int step = 0; step < 2 * n - 1; step++) {
            char bst = 'Z' + 1;

            // Tìm ký tự nhỏ nhất trong q
            for (int[] p : q) {
                bst = (char) Math.min(bst, grid[p[0]].charAt(p[1]));
            }
            ans.append(bst);

            Deque<int[]> nextq = new ArrayDeque<>();
            for (int[] p : q) {
                int x = p[0], y = p[1];
                if (grid[x].charAt(y) != bst) continue;

                if (x + 1 < n && !visited[x + 1][y]) {
                    visited[x + 1][y] = true;
                    nextq.add(new int[]{x + 1, y});
                }
                if (y + 1 < n && !visited[x][y + 1]) {
                    visited[x][y + 1] = true;
                    nextq.add(new int[]{x, y + 1});
                }
            }
            q = nextq;
        }

        System.out.println(ans.toString());
        sc.close();
    }
}
