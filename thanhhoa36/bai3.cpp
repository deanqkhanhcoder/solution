#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("inline") 
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i){
        int dif = a[i] - a[i - 1];
        ll need = (ll)dif * i;
        if (need <= (ll)m){
            m -= need;
        } else {
            cout << a[i - 1] + m/i;
        }
    }
    cout << a[n - 1] + m/n;
    return 0;
}
