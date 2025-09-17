#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n,int from,int to,int aux){
    if (n == 1){
        cout << from << ' ' << to << "\n";
        return;
    }
    hanoi(n-1, from, aux, to);
    cout << from << ' ' << to << "\n";
    hanoi(n-1, aux, to, from);
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    int k; cin >> k;
    cout << (1 << k) - 1 << "\n";
    hanoi(k, 1, 3, 2);
    return 0;
}