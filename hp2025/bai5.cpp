#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int &e : a) cin >> e;
    int r1 = *min_element(a.begin(), a.end());
    int r2 = *max_element(a.begin(), a.end());
    int range = r2 - r1 + 1;
    vector<int> cnt(range, 0);
    for(int d = 1; d <= r2; d++){
        int start = ((r1 + d - 1) / d) * d;
        for(int x = start; x <= r2; x += d){
            int idx = x - r1;
            cnt[idx]++;
        }
    }
    vector<int> d(n);
    for(int i = 0; i < n; i++){
        d[i] = cnt[a[i] - r1];
        cout << d[i] << " ";
    }
    cout << "\n";
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && d[st.top()] <= d[i])
            st.pop();
        if(!st.empty())
            ans[i] = a[st.top()];
        st.push(i);
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
