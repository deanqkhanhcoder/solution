#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solution(int n){
    if (n % 4 == 1 || n % 4 == 2){
        cout << "NO";
        return;
    }
    cout << "YES\n";
    ll target = n * (n + 1LL) / 4; int i;
    vector<int> v;
    for (i = n; i > 0; --i){
        target -= i;
        v.push_back(i);
        if (target == 0){
            break;
        } else if (target < i) {
            v.push_back(target);
            break;
        }
    }
    cout << v.size() << "\n";
    for (auto x : v){
        cout << x << ' ';
    }
    cout << "\n" << n - v.size() << "\n";
    for (--i; i > 0; --i){
        if (i != target){
            cout << i << ' ';
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    solution(n);
    return 0;
}