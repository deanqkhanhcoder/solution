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
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    int ans = 0;
    auto started = [&](int index) -> int{
        int res = 1;
        int l = index, r = index;
        int boom = 1;
        while (true){
            int lastr = r;
            while (r != -1 && r + 1 < n && a[r + 1] <= a[lastr] + boom){
                r++;
            }
            if (r != -1 && lastr == r){
                r = -1;
            } else {
                res += (r - lastr);
            }
            int lastl = l;
            while (l != -1 && l - 1 >= 0 && a[l - 1] >= a[lastl] - boom){
                l--;
            }
            if (l != -1 && lastl == l){
                l = -1;
            } else {
                res += (lastl - l);
            }
            if (l == -1 && r == -1){
                break;
            }
            boom++;
            // cerr << "r : " << r << " a[r] : " << a[r] << endl;
            // cerr << "boom :" << boom << endl;
            // if (boom == 4){
            //     cerr << "a[r + 1] : " << a[r] << " a[r] : " << a[r - 1] << endl; 
            // }
            // cerr << "res : " << res << endl;
        }
        return res;
    };
    for (int i = 0; i < n; ++i){
        ans = max(ans, started(i));
    }
    cout << ans;
}