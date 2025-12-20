#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = (int)s.size();
    int cnt = 0;
    stack<char> st;
    for (int i = 0; i < n; ++i){
        char c = s[i];
        if (!st.empty() && st.top() == c){
            st.pop();
            cnt++;
        } else {
            st.push(c);
        }
    }
    cout << (cnt % 2 ? "Bob" : "Alice");
    return 0;
}