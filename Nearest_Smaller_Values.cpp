#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a[n+1];
    stack<int> st;
    st.push(0);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        while (st.top() != 0 && a[st.top()] >= a[i]){
            st.pop();
        }
        cout << st.top() << ' ';
        st.push(i);
    }
    return 0;
}