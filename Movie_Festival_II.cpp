#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<pair<int,int>> ab(n);
    for(int i = 0; i < n ; i++) cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end(), [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    });
    int ans = 0;
    multiset<int> ms;
    for(int i = 0; i < k; i++) ms.insert(0);
    for (pair<int, int> &p : ab){
        auto it = ms.upper_bound(p.first);
        if (it != ms.begin()){
            it--;
            ans++;
            ms.erase(it);
            ms.insert(p.second);
        }
    }
    cout << ans;
    return 0;
}