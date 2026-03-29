#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n; ll k;
const int maxN = 1e5 + 1;
ll a[maxN];
ll prefix[maxN];

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    ll res = 0;
    for(int i = 1; i <= n; i++){
        ll target = prefix[i] - k;
        int l = 0, r = i - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if (prefix[mid] <= target) l = mid;
            else r = mid - 1;
        }
        if (prefix[l] <= target) res += (l + 1);
    }
    cout << res;
    return 0;
}