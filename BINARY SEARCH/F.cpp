#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> st;
    st.reserve(2);
    ll cnt = 0;
    for (int i = 1; i <= n; ++i){
        int a; cin >> a;
        // if ((int)st.size() == 2) st.erase(st.begin());
        while (!st.empty() && st.back().first < a){
            cnt += st.back().second;
            st.pop_back();
        }
        if (!st.empty() && st.back().first == a){
            cnt += st.back().second;
            st.back().second += 1;
            if ((int)st.size() > 1) cnt++;
        } else {
            if (!st.empty()) cnt += 1;
            st.push_back({a, 1});
        }
        // cout << "cnt : " << cnt << endl;
    }
    cout << cnt;
    return 0;
}