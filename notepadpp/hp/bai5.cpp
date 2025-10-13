#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<pair<int,int>,int>& a,const pair<pair<int,int>,int>& b) {
    if (a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.first.second > b.first.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<pair<int,int>, int>> a(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = {{l, r}, i};
    }
    sort(a.begin(), a.end(), cmp);
    vector<int> c(n, 0);
    vector<int> cd(n, 0);
    int maxr = 0;
    for (auto &p : a) {
        int r = p.first.second;
        int idx = p.second;
        if (r <= maxr) cd[p.second] = 1;
        else maxr = r;
    }
    int minr = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        int r = a[i].first.second;
        if (r >= minr) c[a[i].second] = 1;
        else minr = r;
    }
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << cd[i] << " ";
    }
    return 0;

}