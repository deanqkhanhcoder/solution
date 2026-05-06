#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n, f;
    string s;
    cin >> n >> f >> s;
    unordered_map<string, int> mp;
    set<string> st;
    auto check = [&](string str) -> bool{
        return (str[0] != str[1] && str[1] == str[2]);
    };
    auto addpoint = [&](int pos, char c, int delta){
        for (int i = max(pos - 2, 0); i <= min(pos, n - 3); ++i){
            string str;
            str.reserve(3);
            str.push_back(s[i]);
            str.push_back(s[i + 1]);
            str.push_back(s[i + 2]);
            str[pos - i] = c;
            if (check(str)){
                mp[str] += delta;
                if (mp[str] >= f){
                    st.insert(str);
                }
            }
        }
    };
    for (int i = 0; i <= n - 3; ++i){
        string str;
        str.reserve(3);
        str.push_back(s[i]);
        str.push_back(s[i + 1]);
        str.push_back(s[i + 2]);
        if (check(str)){
            mp[str]++;
            if (mp[str] >= f){
                st.insert(str);
            }
        }
    }
    for (int i = 0; i < n; ++i){
        addpoint(i, s[i], -1);
        for (char c = 'a'; c <= 'z'; ++c){
            if (c == s[i]) continue;
            addpoint(i, c, 1);
            addpoint(i, c, -1);
        }
        addpoint(i, s[i], 1);
    }
    cout << (int)st.size() << endl;
    for (const string &s : st){
        cout << s << endl;
    }
    return 0;
}