#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<int> a;
int n; ll k;
bool check(ll mid){
    ll cnt = 0;
    int j = 0;
    for (int i = 0; i < n; ++i){
        while (j < i && a[i] - a[j] > mid){
            j++;
        }
        cnt += i - j;
    }
    return cnt >= k;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    a.resize(n);
    for (int &e : a) cin >> e;
    sort(a.begin(), a.end());
    ll lo = 0;
    ll hi = a.back() - a.front();
    while (lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo;
    return 0;
}