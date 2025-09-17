#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>
using namespace std;
struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        x += FIXED_RANDOM;
        x ^= (x >> 23) ^ (x << 16);
        return x;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    unordered_map<int, int, custom_hash> mp;
    for (int i = 0; i < n; ++i){
        int ai; cin >> ai;
        int cop = x - ai;
        if (mp.find(cop) != mp.end()){
            cout << mp[cop] + 1 << ' ' << i + 1;
            return 0;
        }
        mp[ai] = i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}