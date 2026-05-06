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
    string s; cin >> s;
    int n = s.length();
    bool ok = false;
    for (int i = n - 1; i >= 1; --i){
        if (s[i] == '9'){
            continue;
        } else {
            if (s[i - 1] == '0') continue;
            ok = true;
            s[i]++;
            s[i - 1]--;
            int suffs = 0;
            for (int j = i; j < n; ++j){
                int d = (s[j] - '0');
                suffs += d;
                // cerr << "cc" << endl;
            }
            for (int j = i; j < n; ++j){
                int fill = (suffs > 9 ? 9 : suffs);
                s[j] = (char)(fill + '0');
                suffs -= fill;
                // cerr << "cc" << endl;
            }
            break;
        }
    }
    if (s[0] == '0') ok = false;
    cout << (ok ? s : "0");
    return 0;
}
