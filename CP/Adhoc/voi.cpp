#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
constexpr int MAXN = 670;
constexpr int INF = (int)1e9;
int n, q, x, y;
vector<pair<int,int>> d;
int ans[MAXN][MAXN];
bool check(int pos){
    return pos >= 0 && pos < MAXN;
}

vector<pair<int,int>> lv;
vector<pair<int,int>> ld;
void dfsx(int i, int dv, int dd){
    if (i == x){
        lv.push_back({dv, dd});
        return;
    }
    dfsx(i + 1, dv + 1, dd);
    dfsx(i + 1, dv - 1, dd + 1);
    dfsx(i + 1, dv, dd - 1);
}

void dfsy(int i, int dv, int dd){
    if (i == x){
        ld.push_back({dv, dd});
        return;
    }
    dfsy(i + 1, dv, dd + 1);
    dfsy(i + 1, dv + 1, dd - 1);
    dfsy(i + 1, dv - 1, dd);
}
void init(){
    // for (int x0 = 0; x0 <= x; ++x0){
    //     // x0 tat -> vang
    //     for (int x1 = 0; x1 <= x - x0; ++x1){
    //         int x2 = x - x0 - x1;
    //         // x1 vang -> do
    //         // x2 do -> tat
    //         for (int y0 = 0; y0 <= y; ++y0){
    //             // y0 tat -> do
    //             for (int y1 = 0; y1 <= y - y0; ++y1){
    //                 int y2 = y - y0 - y1;
    //                 // y1 vang -> tat
    //                 // y2 do -> vang
    //                 int d1 = -x1 - y1 + x0 + y2;
    //                 // d1 tong vang da thay doi
    //                 int d2 = -x2 - y2 + x1 + y0;
    //                 // d2 tong do da thay doi
    //                 d.push_back({d1, d2});
    //             }
    //         }
    //     }
    // }
    for (pair<int, int> &a: lv){
        for (pair<int, int> &b : ld){
            d.push_back({a.first + b.first, a.second + b.second});
        }
    }
    memset(ans, 0x3f, sizeof(ans));
    queue<pair<int,int>> q;
    q.push({0, 0});
    ans[0][0] = 0;
    while(!q.empty()){
        int c1 = q.front().first;
        int c2 = q.front().second;
        q.pop();
        for (auto &m : d){
            int nextc1 = c1 - m.first;
            int nextc2 = c2 - m.second;
            // nextc1 loang ra
            // nextc2 loang ra
            if (check(nextc1) && check(nextc2)){
                if (nextc1 + nextc2 > n) continue;
                if (ans[nextc1][nextc2] > INF){
                    ans[nextc1][nextc2] = ans[c1][c2] + 1;
                    q.push({nextc1, nextc2});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q >> x >> y;
    init();
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<int> pref1(n + 1, 0);
    vector<int> pref2(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        pref1[i] = pref1[i - 1] + (a[i - 1] == 1);
        pref2[i] = pref2[i - 1] + (a[i - 1] == 2);
    }
    while (q--){
        int l, r; cin >> l >> r;
        int c1 = pref1[r] - pref1[l - 1];
        int c2 = pref2[r] - pref2[l - 1];
        cerr << "c1 : " << c1 << "c2 : " << c2 << endl;
        cout << (ans[c1][c2] > INF ? -1 : ans[c1][c2]) << '\n';
    }
    return 0;

}