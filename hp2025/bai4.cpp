#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<deque<int>> pos(26);
    for (int i = 0; i < n; i++)
        pos[s[i] - 'a'].push_back(i);
    while (q--){
        int t; cin >> t;
        if (t == 0){
            for (int c = 0; c < 26; c++){
                if (!pos[c].empty()){
                    s[pos[c].front()] = '.';
                    pos[c].pop_front();
                    break;
                }
            }
        } else {
            for (int c = 25; c >= 0; c--){
                if (!pos[c].empty()){
                    s[pos[c].front()] = '.';
                    pos[c].pop_front();
                    break;
                }
            }
        }
    }
    for (char c : s)
        if (c != '.') cout << c;
    return 0;
}
