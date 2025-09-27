#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
using namespace std;
bool check(int a){
    int res = 0;
    for (int i = 1; i * i <= a; ++i){
        if (a % i == 0){
            res += i;
            if (a / i != i){
                res += a / i;
            }
        }
    }
    return 2*a <= res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("GHH.INP", "r", stdin);
    freopen("GHH.OUT", "w", stdout);
    int n; cin >> n;
    vector<int> ans;
    ans.reserve(n);
    while (n--){
        int a; cin >> a;
        if (check(a)) ans.push_back(a);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); ++i){
        cout << ans[i] << "\n";
    }
}