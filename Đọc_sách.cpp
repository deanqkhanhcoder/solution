#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k; 
vector<int> a;

bool check(int mid) {
    int last = a[0], cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - last >= mid) {
            cnt++;
            last = a[i];
            if (cnt >= k) return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    a.resize(n);
    for (int &e : a){
        cin >> e;
    }
    if (n == 1 || k == 1){
        cout << 0;
        return 0;
    }
    sort(a.begin(), a.end());
    int hi = a.back() - a.front();
    int lo = 0;
    while (lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo;
}