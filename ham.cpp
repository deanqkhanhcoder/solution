#include <iostream>
using namespace std;

int tinhtong(int a, int b, int c){
    int sum = a + b + c;
    return sum;
}

int main(){
    int a, b, c; cin >> a >> b >> c;
    cout << tinhtong(a, b, c) << endl;
    return 0;
}