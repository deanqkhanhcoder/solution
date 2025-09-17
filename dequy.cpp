#include <iostream>
using namespace std;

void A(int n){
    cout << n << endl;
    A(n - 1);
}

int main(){
    int n = 30;
    A(n);
    return 0;
}