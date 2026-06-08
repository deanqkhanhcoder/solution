#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
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
    auto get_area = [&](double d, int h) -> double{
        return d * h / 2;
    };
    while (t--){
        int n, d, h; cin >> n >> d >> h;
        vector<int> point(n);
        for (int &e : point) cin >> e;
        double s = 0;
        for (int i = 0; i < n; ++i){
            if (i == 0){
                s += get_area(d, h);
            } else if (point[i] >= point[i - 1] + h){
                s += get_area(d, h);
            } else {
                int h_overlap = point[i - 1] + h - point[i];
                double d_overlap = (double) d / h * (double) h_overlap;
                s += get_area(d, h);
                s -= get_area(d_overlap, h_overlap);
            }
        }
        cout << fixed << setprecision(6) << s << endl;
    }
    return 0;
}