#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a; cin >> a;
    int n = a.size();
    vector<int> v(26, 0);
    for (int i = 0; i < n; ++i){
        v[a[i] - 'A']++;
    }
    if (n % 2 == 0){
        for (int i = 0; i < 26; ++i){
            if (v[i] != 0 && (v[i] & 1) == 1){
                cout << "NO SOLUTION";
                return 0;
            }
        }
        for (int j = 0; j < 26; ++j){
            if (v[j] != 0){
                cout << string(v[j] / 2, char('A' + j));
            }
        }
        for (int j = 25; j >= 0; --j){
            if (v[j] != 0){
                cout << string(v[j] / 2, char('A' + j));
            }
        }
    } else {
        int idx = -1, cnt = 0;
        for (int i = 0; i < 26; ++i){
            if (v[i] != 0){
                if ((v[i] & 1) == 1){
                    idx = i;
                    cnt++;
                }
            }
        }
        if (cnt != 1){
            cout << "NO SOLUTION";
            return 0;
        } else {
            for (int j = 0; j < 26; ++j){
                if (v[j] != 0 && j != idx){
                    cout << string(v[j] / 2, char('A' + j));
                }
            }
            cout << string(v[idx], char('A' + idx));
            for (int j = 25; j >= 0; --j){
            if (v[j] != 0 && j != idx){
                    cout << string(v[j] / 2, char('A' + j));
                }
            }
        }
    }       
    return 0;
}