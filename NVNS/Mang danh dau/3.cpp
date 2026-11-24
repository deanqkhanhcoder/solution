#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define endl '\n'
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr ll INFLL = (ll)1e18;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here    
    int n; cin >> n;
    vector<vector<int>> cards(n);
    for (int i = 0; i < n; ++i){
        int m; cin >> m;
        cards[i].resize(m);
        for (int j = 0; j < m; ++j){
            cin >> cards[i][j];
        }
    }
    constexpr int MAXA = (int)1e5 + 5;
    bitset<MAXA> mask;
    for (int i = 0; i < n; ++i){
        for (int card : cards[i]){
            mask[card] = 1;
        }
        for (int j = 0; j < n; ++j){
            if (i == j) continue;
            if (sz(cards[j]) > sz(cards[i])) continue;
            bool ok = true;
            for (int card : cards[j]){
                if (!mask[card]){
                    ok = false;
                    break;
                }
            }    
            if (ok) {
                cout << "NO" << endl;
                goto end;
            }
        }
        cout << "YES" << endl;
        end:;
        mask.reset();
    }
    return 0;
}