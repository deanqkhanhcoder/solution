#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define lowbit(i) ((i) & (-(i)))
using namespace std;
using ll = long long;
int n;
vector<int> BIT;

void update(int pos, int val){
    for (; pos <= n; pos += lowbit(pos)){
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
    int k; cin >> n >> k;
    vector<int> a(n);
    BIT.assign(n + 1, 0);
    for (int &e : a) cin >> e;
    ll curr = 0;
    for (int i = 0; i < n; ++i){
        curr += i - query(a[i]);
        update(a[i], 1);
    }
    // cerr << curr;
    ll ans = curr;
    for (int step = 0; step < k - 1; ++step){
        int i = n - 2;
        while (i >= 0 && a[i] > a[i + 1]) i--;
        if (i < 0) break;
        ll len = (n - 1) - (i + 1) + 1;
        ll minus = (ll)(len * (len - 1)) / 2;
        curr -= minus;
        for (int x = i + 1; x < n; ++x){
            if (a[i] > a[x]) curr--;
        }
        int j = n - 1;
        while (a[j] < a[i]) j--;
        swap(a[i], a[j]);
        reverse(a.begin() + i + 1, a.end());
        for (int x = i + 1; x < n; ++x){
            if (a[i] > a[x]) curr++;
        }
        ans += curr;
    }
    for (int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
    cout << endl;
    cout << ans;
    return 0;
}