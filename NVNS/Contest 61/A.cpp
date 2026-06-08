#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int T; cin >> T;
    auto nextnum = [](int x){
        int ans = 0;
        while (x){
            int d = x % 10;
            ans += d * d;
            x /= 10;
        }
        return ans;
    };
    while (T--){
        int x, v, n; cin >> x >> v >> n;
        unordered_map<int, int> visited;
        visited.reserve(1e4);
        visited.max_load_factor(0.7);
        vector<int> sq;
        sq.reserve(1e4);
        int curr = x;
        while (!visited.count(curr)){
            visited[curr] = (int)sq.size();
            sq.push_back(curr);
            curr = nextnum(curr);
        }
        int sq_size = (int)sq.size();
        int cycle_started = visited[curr];
        int cycle_len = sq_size - cycle_started;
        ll ans = 0;
        for (int i = 0; i < min((int)sq.size(), n); ++i){
            if (sq[i] == v){
                ans++;
            }
        }
        if (n <= sq_size){
            cout << ans << endl;
            continue;
        } else {
            int remain = n - sq_size;
            int cycle_cnt = 0;
            for (int i = cycle_started; i < sq_size; ++i){
                if (sq[i] == v){
                    cycle_cnt++;
                }
            }
            ans += 1LL * (remain / cycle_len) * cycle_cnt;
            int extra = remain % cycle_len;
            for (int i = 0; i < extra; ++i){
                if (sq[cycle_started + i] == v){
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}