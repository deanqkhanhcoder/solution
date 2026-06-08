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
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int sz = (int)s.size();
        char last = s[0];
        vector<int> A_segment;
        int total_a = 0;
        int total_b = 0;
        int run = 1;
        for (int i = 1; i < sz; ++i){
            if (last != s[i]){
                if (last == 'A'){
                    A_segment.push_back(run);
                    total_a += run;
                } else if (last == 'B'){
                    total_b += min(2, run);
                }
                run = 0;
            }
            run++;
            last = s[i];
        }
        if (last == 'A'){
            A_segment.push_back(run);
            total_a += run;
        } else if (last == 'B'){
            total_b += min(2, run);
        }
        if (total_b < (int)A_segment.size()){
            int mn = *min_element(all(A_segment));
            cout << total_a - mn << endl;
        } else {
            cout << total_a << endl;
        }
    }
    return 0;
}