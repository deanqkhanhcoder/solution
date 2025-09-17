/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    sort(p.begin(), p.end());
    int i = 0, j = n - 1;
    int cabin = 0;
    while (i <= j){
        if (p[i] + p[j] <= x){
            i++;
            j--;
            cabin++;
        } else if (p[i] + p[j] > x) {
            j--;
            cabin++;
        }
    }
    cout << cabin;
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; 
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    sort(p.begin(), p.end());
    int cabin = 0;
    for (int i = 0, j = n - 1; i <= j;){
        if (p[i] + p[j] <= x){
            i++;
            j--;
        } else {
            j--;
        }
        cabin++;
    }
    cout << cabin;
    return 0;
}
