#include <iostream>
#include <vector>
using namespace std;
void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(){
    FastIO();
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    int l = 0, r = n - 1;
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (a[mid] == x){
            cout << mid;
            break;
        } else if (a[mid] < x){
            l = mid + 1;
        } else {
            r = mid - 1;
        }        
    }
    return 0;
}