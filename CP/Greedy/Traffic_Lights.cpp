#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n; cin >> x >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    set<int> ps = {0, x};
    map<int,int> freq;
    freq[x] = 1;
    for (int d : p) {
        auto it = ps.upper_bound(d);
        int r = *it, l = *prev(it);
        int len = r - l;
        if (--freq[len] == 0) freq.erase(len);
        freq[d - l]++; freq[r - d]++;
        ps.insert(d);
        cout << freq.rbegin()->first << " ";
    }
}