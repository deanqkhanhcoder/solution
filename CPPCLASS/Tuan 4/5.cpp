/*
X = a + (a + 1) + (a + 2) ... (a + k - 1)
a >= 1; k >= 2
X = k * (2a + k - 1) / 2;
2X = k * (2a + k - 1)
ta thấy k chẵn thì 2a + k - 1 lẻ và ngược lại
đặt L = số lẻ; C là số chẵn
=> 2X = C * L
giả sử k lẻ thì (2a + k - 1) chẵn với mọi a >= 1;
với mỗi k = L (lẻ) thì đều có C (chẵn ở đây là k) TM vì 2X chẵn
(2a + k - 1) lẻ thì k chẵn;
tương tự với mỗi (2a + k - 1) = L (lẻ) thì đều có C (chẵn ở đây là 2a + k - 1) vì 2X chẵn;
vậy ta cần số số ước lẻ trong 2X hay là X
2X = 2^a1 * p2^a2 ...
X = 2^(a1 - 1) * p2^a2 ...
số ước lẻ là tích của (a_i + 1)
với n! thì số ước lẻ là tích (Legendre(p_i) + 1)
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "SUMFACT"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n, m; cin >> n >> m;
    vector<bool> ip(n + 1, true);
    vector<int> primes;
    ip[0] = ip[1] = false;
    for (int i = 2; i <= n; ++i){
        if (ip[i]){
            primes.push_back(i);
        }
        for (int p : primes){
            if (1LL * i * p > n) break;
            ip[i * p] = false;
            if (i % p == 0) break;
        }
    }
    ll ans = 1;
    auto calc = [&](int n, int p){
        int curr_n = n;
        int ep = 0;
        while (curr_n){
            curr_n /= p;
            ep += curr_n;
        }
        return ep;
    };
    for (int p : primes){
        if (p == 2) continue;
        ans *= (1LL + calc(n, p));
        ans %= m;
    }
    cout << (ans - 1 + m) % m << endl;
    return 0;
}