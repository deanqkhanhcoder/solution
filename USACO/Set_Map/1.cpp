#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n; cin >> n;
    string s; cin >> s;
    for (int len = 1; len <= n; ++len){
        set<deque<char>> sub;
        deque<char> dq;
        for (int i = 0; i + len - 1 < n; ++i){
            int j = i + len - 1;
            if (dq.empty()){
                for (int i = 0; i < len; ++i){
                    dq.push_back(char(s[i]));
                }
            } else {
                dq.pop_front();
                dq.push_back(char(s[j]));
            }
            if (sub.count(dq)) goto end;
            sub.insert(dq);
        }
        cout << len;
        return 0;
        end:;
    }
    cout << -1;
    return 0;
}