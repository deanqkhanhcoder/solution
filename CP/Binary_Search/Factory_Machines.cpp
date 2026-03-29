#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t; cin >> n >> t;
    vector<int> k(n);
    int mk = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        mk = min(mk, k[i]);
    }
    ll low = 0, high = (ll)mk * t;
    while (low < high){
        ll mid = low + (high - low) / 2;
        ll prod = 0;
        for (int time : k){
            prod += mid / time;
            if (prod >= t) break;
        }
        if (prod >= t) high = mid;
        else low = mid + 1;
    }
    cout << low;
    return 0;
}