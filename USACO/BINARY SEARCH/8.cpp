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
constexpr int INF = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define TASK "angry"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    // code here
    /*
    L[i] = min(j < i, max(L[j] + 1, x[i] - x[j]))
    ta tấy L[j] + 1 tăng dần theo j, còn x[i] - x[j] giảm dần vì x[j] tăng dần
    do đó min(j < i, max(L[j], x[i] - x[j])) là 1 hàm hình chữ V
    min lanh quanh tại điểm cực trị L[j] sấp sĩ x[i] - x[j]
    ta sẽ tìm L[j] + 1 cuối cùng <= x[i] - x[j];
    tương tự với R[i] = min(i < j, max(L[j] + 1, x[i] - x[j]))
    L[j] + 1 tăng dần, và x[i] - x[j] giảm dần
    */
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    vector<int> L(n), R(n);
    L[0] = 0;
    for (int j = 0, i = 1; i < n; ++i){
        while (j + 1 < i && L[j + 1] + 1 <= a[i] - a[j + 1]){
            j++;
        }
        L[i] = max(L[j] + 1, a[i] - a[j]);
        if (j + 1 < i){
            L[i] = min(L[i], max(L[j + 1] + 1, a[i] - a[j + 1]));
        }
    }
    R[n - 1] = 0;
    for (int j = n - 1, i = n - 2; i >= 0; --i){
        while (j - 1 > i && R[j - 1] + 1 <= a[j - 1] - a[i]){
            j--;
        }
        R[i] = max(R[j] + 1, a[j] - a[i]);
        if (j - 1 > i){
            R[i] = min(R[i], max(R[j - 1] + 1, a[j - 1] - a[i]));
        }
    }
    auto check = [&](double r){
        if ((double)(a.back() - a.front()) <= 2 * r) return true;
        int i_max = -1;
        for (int i = 0; i < n; ++i){
            if ((double)L[i] <= r - 1) i_max = i;
            else break;
        }
        int j_max = -1;
        for (int j = n - 1; j >= 0; --j){
            if ((double)R[j] <= r - 1) j_max = j;
            else break;
        }
        if (i_max == -1 || j_max == -1) return false;
        if (i_max >= j_max) return true;
        return ((double)(a[j_max] - a[i_max]) <= 2 * r);
    };
    double lo = 0, hi = a[n - 1] - a[0];
    for (int iter = 0; iter < 60; ++iter){
        double mid = (hi + lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << fixed << setprecision(1) << (lo + hi) / 2;
    return 0;
}