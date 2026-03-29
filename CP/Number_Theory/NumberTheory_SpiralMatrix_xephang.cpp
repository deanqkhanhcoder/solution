#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define lowbit(i) ((i) & (-(i)))
using namespace std;
vector<int> BIT;
int s;
void update(int pos, int val){
    for (; pos <= s; pos += lowbit(pos)){
        BIT[pos] += val;
    }
}
int query(int pos){
    int ans = 0;
    for (; pos > 0; pos -= lowbit(pos)){
        ans += BIT[pos];
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    vector<int> x(q);
    for (int &e : a) cin >> e;
    for (int &e : x) cin >> e;
    // cerr << "ok";
    vector<int> all = a;
    for (int e : x) all.push_back(e);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    s = (int)all.size();
    BIT.assign(s + 1, 0);
    auto idx = [&](int val){
        return lower_bound(all.begin(), all.end(), val) - all.begin() + 1;
    };
    for (int &e : a){
        int pos = idx(e);
        update(pos, 1);
    }
    for (int &e : x){
        int pos = idx(e);
        int ans = query(pos) + 1;
        cout << ans << '\n';
        update(pos, 1);
    }
    return 0;
}