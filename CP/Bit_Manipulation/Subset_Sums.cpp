#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using ll = long long;
constexpr int B = 320;
constexpr int LIMIT = (int)1e5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n);
    for (ll &e : a) cin >> e;
    vector<vector<int>> s(m);
    vector<int> heavy;
    vector<int> idh(LIMIT + 1, -1);
    int idx = 0;
    // cerr << "ok";
    for (int i = 0; i < m; ++i){
        int k; cin >> k;
        s[i].resize(k);
        for (int &e : s[i]){
            cin >> e;
            --e;
            // cerr << e << '\n';
        }
        if (s[i].size() > B){
            idh[i] = idx++;
            heavy.push_back(i);
        }
    }
    int H = heavy.size();
    // cout << H;
    vector<ll> sum(H, 0);
    vector<ll> lazy(H, 0);
    for (int i = 0; i < H; ++i){
        for (int j : s[heavy[i]]){
            sum[i] += a[j];
        }
    }
    vector<vector<int>> cnt(H, vector<int>(H, 0));
    bitset<LIMIT + 1> mask;
    for (int h1 = 0; h1 < H; ++h1){
        mask.reset();
        for (int x : s[heavy[h1]]){
            mask[x] = 1;
        }
        for (int h2 = 0; h2 < H; ++h2){
            if (h1 == h2){
                cnt[h1][h2] = s[heavy[h2]].size();
                continue;
            }
            if (cnt[h2][h1] != 0){
                cnt[h1][h2] = cnt[h2][h1];
                continue;
            }
            int c = 0;
            for (int x : s[heavy[h2]]) if (mask[x]) c++;
            cnt[h1][h2] = c;
        }
    }
    vector<vector<int>> bh(n);
    for (int i = 0; i < H; ++i){
        for (int x : s[heavy[i]]){
            bh[x].push_back(i);
        }
    }
    while (q--){
        char type; cin >> type;
        if (type == '?'){
            int k; cin >> k;
            k--;
            ll ans = 0;
            if (idh[k] != -1){
                int id = idh[k];
                ans = sum[id];
                for (int h = 0; h < H; ++h){
                    ans += lazy[h] * cnt[h][id];
                }
                cout << ans << '\n';
            } else {
                for (int x : s[k]){
                    ll cur = a[x];
                    for (int h : bh[x]){
                        cur += lazy[h];
                    }
                    ans += cur;
                }
                cout << ans << '\n';
            }
        } else {
            int k; cin >> k;
            k--;
            int x; cin >> x;
            if (idh[k] != -1){
                lazy[idh[k]] += x;
            } else {
                for (int i : s[k]){
                    a[i] += x;
                    for (int h : bh[i]){
                        sum[h] += x;
                    }
                }
            }
        }
    }
    return 0;
}