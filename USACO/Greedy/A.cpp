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
     freopen("race.in", "r", stdin);
     freopen("race.out", "w", stdout);
    int k, n; cin >> k >> n;
    while (n--){
        int X; cin >> X;
        int lo = 1, hi = k;
        auto calc = [&](int mid){
            ll s1 = 1LL * mid * (mid + 1) / 2;
            if (mid <= X) return s1;
            ll s2 = 1LL * (mid - 1 + X) * (mid - X) / 2;
            return s1 + s2;
        };
        while (lo < hi){
            int mid = (lo + hi + 1) / 2;
            if (calc(mid) <= k) lo = mid;
            else hi = mid - 1;
        }
        int peak = lo;
        int dist = calc(peak);
        // cerr << "peak : " << peak << " dist : " << dist << endl;
        int time = 0;
        if (peak <= X){
            time += peak;
            int rem = k - dist;
            time += (rem + peak - 1) / peak;
        } else {
            time += peak + (peak - X);
            int rem = k - dist;
            time += (rem + peak - 1) / peak;
        }
        cout << time << endl;;
    }
    return 0;
}
