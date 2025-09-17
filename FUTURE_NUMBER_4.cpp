#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const int MAX_N = (int)3e7;
vector<int>prime = {2};
vector<int>sum (MAX_N + 1);
int n;
int L, R;

void s(){
	vector <bool> isPrime(MAX_N / 2 + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 3; i <= MAX_N / 2; i += 2) {
         if(isPrime[i] == true) {
         	prime.push_back(i);
            for(int j = i * i; j <= MAX_N / 2; j += i * 2)
                isPrime[j] = false;
        }
    }
}

void p()
{
	sum.assign(MAX_N,0);
	int y = 0;
	for (int i = 0; prime[i] * prime[i] <= MAX_N; i++)
		for (int j = i; j < prime.size() && prime[i] * prime[j] <= MAX_N; j++)
		    sum[prime[i] * prime[j]] = prime[i] * prime[j];
	sum.push_back(0);
	for (int i = 1; i < MAX_N; i++)
	{
		sum[i] += sum[i - 1];
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    s(); p();
    cin >> n;
    while (n--){
        int l,r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << '\n';
    }
    return 0;
}
