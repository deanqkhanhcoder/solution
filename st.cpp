#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> right(n+1, -1), left(n+1, -1);
    {
        vector<int> st(n);
        st.reserve(n);
        for (int i = 1; i <= n; ++i) {
            while (!st.empty() && a[i] > a[st.back()]) {
                right[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
    }
    {
        vector<int> st;
        st.reserve(n);
        for (int i = n; i >= 1; --i) {
            while (!st.empty() && a[i] > a[st.back()]) {
                left[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        int L = left[i], R = right[i];
        int ans = -1;
        if (L == -1 && R == -1) ans = -1;
        else if (L == -1) ans = R;
        else if (R == -1) ans = L;
        else {
            int dL = i - L;
            int dR = R - i;
            if (dL <= dR) ans = L; // tie -> left
            else ans = R;
        }
        if (i > 1) cout << ' ';
        cout << ans;
    }
    cout << '\n';
    return 0;
}