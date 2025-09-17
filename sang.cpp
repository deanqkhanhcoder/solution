#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<bool> ssnt(ll n){
    vector<bool> isprime(n + 1, true);
    isprime[0] = isprime[1] = false;
    for (ll i = 4; i <= n; i += 2)
        isprime[i] = false;
    for (ll i = 3; i * i <= n; i += 2){
        if (isprime[i]){
            for (ll j = i * i; j <= n; j += 2 * i)
                isprime[j] = false;
        }
    }
    return isprime;
}
void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(){
    FastIO();
    ll n; cin >> n;
    vector<bool> snt = ssnt(n);
    if (n > 1) cout << 2 << ' ';
    for (ll i = 3; i <= n; i += 2){
        if (snt[i]) cout << i << ' ';
    }
    return 0;
}