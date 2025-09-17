#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

bool cmp(const pair<pair<int,int>,int>& a,const pair<pair<int,int>,int>& b) {
    if (a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.first.second > b.first.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<pair<int,int>, int>> inv(n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        inv[i] = {{l, r}, i};
    }
    sort(inv.begin(), inv.end(), cmp);
    vector<int> contains(n, 0);
    vector<int> contained(n, 0);
    int max_r = 0;
    for (auto &p : inv) {
        int r = p.first.second;
        int idx = p.second;
        if (r <= max_r) contained[idx] = 1;
        else max_r = r;
    }
    int min_r = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        int r = inv[i].first.second;
        int idx = inv[i].second;
        if (r >= min_r) contains[idx] = 1;
        else min_r = r;
    }

    for (int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << contained[i] << " ";
    }
    return 0;
}
