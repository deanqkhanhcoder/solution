#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 1e6 + 1;
int cnt[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int maxest = 0;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        cnt[x]++;
        maxest = (x > maxest ? x : maxest);
    }
    for (int i = maxest; i >= 1; --i){
        int m = cnt[i];
        if (m >= 2){
            cout << i;
            return 0;
        }
        for (int j = i * 2; j <= maxest; j += i){
            m += cnt[j];
            if (m >= 2){
                cout << i;
                return 0;
            }
        }
    }
}