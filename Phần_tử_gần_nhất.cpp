#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int MAX = (int)1e6;
using ll = long long;

vector<int> f(int x, const vector<int>& spf){
    vector<int> res;
    while (x > 1) {
        int p = spf[x];
        res.push_back(p);
        while (x % p == 0) x /= p;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;			
    vector<int> spf(MAX + 1, 0);
    for (int i = 2; i <= MAX; ++i){
        if (spf[i] == 0){
            spf[i] = i;
            for (ll j = 1LL * i * i; j <= MAX; j += i){
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> pos(MAX + 1, -1);
    vector<int> lans(n + 1, -1);
    for (int i = 1; i <= n; ++i){
        vector<int> pr = f(a[i], spf);
        int bj = -1;
        int bd = INT_MAX;
        for (int p : pr){
            int j = pos[p];
            if (j != -1){
                int d = i - j;
                if (bj == -1 || d < bd || (d == bd && j < bj)){
                    bj = j;
                    bd = d;
                }
            }
        }
        lans[i] = bj;
        for (int p : pr) pos[p] = i;
    }
							
    fill(pos.begin(), pos.end(), -1);
    vector<int> rans(n + 1, -1);
    for (int i = n; i >= 1; --i){
        vector<int> pr = f(a[i], spf);
        int bj = -1;
        int bd = INT_MAX;
        for (int p : pr){
            int j = pos[p];
            if (j != -1){
                int d = j - i;
                if (bj == -1 || d < bd){
                    bj = j;
                    bd = d;
                }
            }
        }
        rans[i] = bj;
        for (int p : pr) pos[p] = i;
    }				
    for (int i = 1; i <= n; ++i){
        int jl = lans[i];
        int jr = rans[i];
        if (jl == -1 && jr == -1) cout << -1 << " ";
        else if (jl == -1) cout << jr << " ";
        else if (jr == -1) cout << jl << " ";
        else {
            int dl = i - jl;
            int dr = jr - i;
            if (dl < dr) cout << jl << " ";
            else if (dr < dl) cout << jr << " ";
            else cout << jl << " ";
        }
    }
    return 0;

}
