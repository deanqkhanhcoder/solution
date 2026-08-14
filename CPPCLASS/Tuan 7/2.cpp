#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define gcd(a, b) __gcd(a, b);
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;
constexpr int MOD = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code here
    constexpr int MAX_D = 9;
    constexpr int MAX_N = 18;
    constexpr int MAX_S = 9 * (MAX_N + 1);
    constexpr int MAX_W = 285 * (MAX_N + 1);
    vector<int> WIBU(MAX_D + 1);
    WIBU[0] = 0;
    for (int i = 1; i <= MAX_D; ++i){
        WIBU[i] = WIBU[i - 1] + (i * i);
    }
    static int small_gcd[MAX_S + 1][MAX_S + 1];
    for (int i = 0; i <= MAX_S; ++i){
        for (int j = 0; j <= MAX_S; ++j){
            if (i > j) small_gcd[i][j] = small_gcd[j][i];
            else small_gcd[i][j] = gcd()
        }
    }
    auto is_coprime = [&](int a, int b){
        if (a == 0 && b == 0) return false;
        if (a == 0) return b == 1;
        return small_gcd[a][b % a] == 1;
    };
    vector<int> pow_10(MAX_N + 1);
    pow_10[0] = 1;
    for (int i = 1; i <= MAX_N; ++i){
        pow_10[i] = (pow_10[i - 1] * 10) % MOD;
    }
    static int dp_cnt[MAX_N + 1][MAX_S + 1][MAX_D + 1];
    static int dp_sum[MAX_N + 1][MAX_S + 1][MAX_D + 1];
    for (int i = 0; i <= MAX_S; ++i){
        for (int j = 0; j <= MAX_W; ++j){
            dp_cnt[0][i][j] = is_coprime(i, j);
        }
    }
    for (int len = 1; len <= 18; ++len){
        int S_limit = (19 - len) * 9;
        int W_limit  = (19 - len) * 285;
        int d_pow[MAX_D + 1];
        for (int d = 0; d <= MAX_D; ++d){
            d_pow[d] = (1LL * d * pow_10[len - 1]) % MOD;
        }
        for (int i = 0; i <= S_limit; ++i){
            for (int j = 0; j <= W_limit; ++j){
                ll cur_s = 0;
                ll cur_w = 0;
                for (int d = 0; d <= MAX_D; ++d){
                    int nS = d + i;
                    int nW = d + j;
                    int next_c = dp_cnt[len - 1][i][j];
                    int next_s = dp_sum[len - 1][i][j]
                }
            }
        }
    }
    return 0;
}