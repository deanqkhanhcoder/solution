#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> posL;
    vector<int> posQ;
    vector<int> posD;
    for (int i = 0; i < n; ++i){
        if (s[i] == 'L'){
            posL.push_back(i);
        } else if (s[i] == 'Q'){
            posQ.push_back(i);
        } else if (s[i] == 'D'){
            posD.push_back(i);
        }
    }
    int lenL = sz(posL);
    int lenQ = sz(posQ);
    int lenD = sz(posD);
    if (lenL < k || lenQ < k || lenD < k){
        cout << -1 << endl;
        return 0;
    }
    int ans = n + 1;
    int idxQ = 0, idxD = 0;
    for (int i = 0; i + k - 1 < lenL; ++i){
        int currL = posL[i];
        int lastL = posL[i + k - 1];
        while(idxQ < lenQ && posQ[idxQ] <= lastL){
            idxQ++;
        }
        if (idxQ + k - 1 >= lenQ) break;
        int lastQ = posQ[idxQ + k - 1];
        while (idxD < lenD && posD[idxD] <= lastQ){
            idxD++;
        }
        if (idxD + k - 1 >= lenD) break;
        int lastD = posD[idxD + k - 1];
        int len = lastD - currL + 1;
        ans = min(ans, len);
    }
    if (ans > n) cout << -1 << endl;
    else cout << ans - k * 3 << endl;
    return 0;
}