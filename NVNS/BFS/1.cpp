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
    vector<int> pow10(9);
    pow10[0] = 1;
    for (int i = 1; i < 9; ++i){
        pow10[i] = pow10[i - 1] * 10; 
    }
    int n = 0;
    for (int i = 0; i < 9; ++i){
        int x; cin >> x;
        n += pow10[8 - i] * x;
    }
    // cerr << "n : " << n << endl;
    // auto next = [&](int pos, int val){

    // }
    return 0;
}