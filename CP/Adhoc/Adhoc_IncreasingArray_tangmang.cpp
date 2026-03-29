#include <iostream>
using namespace std;
using ll = long long;

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(){
    int n; cin >> n;
    int prev; int curr;
    ll res = 0;
    cin >> prev;
    for (int i = 1; i < n; ++i){
        cin >> curr;
        if (curr < prev){
            res += prev - curr;
        } else {
            prev = curr;
        }
    }
    cout << res;
    return 0;
}