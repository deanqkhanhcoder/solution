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
    int M; cin >> M;
    // int n = (int)s.size();
    // cerr << s << M << endl;
    static int cnt[10];
    int sumd = 0;
    for (char c : s){
        int d = c - '0'; 
        cnt[d]++;
        sumd += d; 
    }
    // cerr << "ok" << endl;
    auto build = [&](const vector<int> &suff) -> string {
        int temp_cnt[10];
        for (int i = 0; i <= 9; i++) temp_cnt[i] = cnt[i];
        for (int d : suff){
            temp_cnt[d]--;
            if (temp_cnt[d] < 0){
                // cout << "ok" << endl;
                return "-1";
            } 
                
        }
        string res = "";
        for (int d = 9; d >= 0; d--){
            res.append(temp_cnt[d], d + '0');
        }
        for (int d : suff) res.push_back(d + '0');
        return res;
    };
    string ans;
    if (M == 6 && sumd % 3 != 0){
        cout << 0;
        return 0;
    }
    if (M == 2 || M == 6){
        for (int i = 0; i <= 8; i += 2){
            string curr = build({i});
            if (curr != "-1" && curr > ans) ans = curr;
        }
    }
    if (M == 10){
        ans = build({0});
    }
    if (M == 4){
        for (int i = 0; i <= 9; ++i){
            for (int j = 0; j <= 9; ++j){
                int num = i * 10 + j;
                if (num % 4 == 0){
                    string curr = build({i, j});
                    if (curr != "-1" && curr > ans) ans = curr;
                }
            }
        }
    }
    if (M == 8){
        // cerr << "ok" << endl;
        for (int i = 0; i <= 9; ++i){
            for (int j = 0; j <= 9; ++j){
                for (int k = 0; k <= 9; ++k){
                    int num = i * 100 + j * 10 + k;
                    if (num % 8 == 0){
                        string curr = build({i, j, k});
                        // cerr << curr << endl;
                        if (curr != "-1" && curr > ans) ans = curr;
                    }
                }
            }
        }
    }
    if (ans == "") cout << 0;
    else cout << ans;
    return 0;
}