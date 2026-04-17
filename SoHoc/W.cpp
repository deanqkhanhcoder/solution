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
    int T; cin >> T;
    while (T--){
        string s; cin >> s;
        int n = s.length();
        if (n & 1){
            cout << (n / 2 == 0 ? "0" : string(n / 2, '9'));
        } else {
            string fi = s.substr(0, n / 2);
            string se = s.substr(n / 2, n);
            if (fi <= se){
                cout << fi;
            } else {
                for (int i = n / 2 - 1; i >= 0; --i){
                    if (fi[i] == '0'){
                        fi[i] = '9';
                    } else {
                        fi[i]--;
                        break;
                    }
                }
                if (fi[0] == '0'){
                    fi.erase(0, 1);
                }
                cout << (fi.length() == 0 ? "0" : fi);
            }
        }
        cout << endl;
    }
    return 0;
}
