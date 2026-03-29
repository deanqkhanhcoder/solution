#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(){
    FastIO();
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (auto i = a.begin(); i != a.end(); ++i){
        cout << *i << ' ';
    }
    cout << '\n';
    for (int i = a.size() - 1; i >= 0; --i)
        cout << a[i] << ' ';
    return 0;
}