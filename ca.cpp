#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    const int N = 1'000'000;
    vector<int> keys(N);
    iota(keys.begin(), keys.end(), 0);
    shuffle(keys.begin(), keys.end(), mt19937(chrono::steady_clock::now().time_since_epoch().count()));

    // ---------- unordered_map ----------
    unordered_map<int,int> um;
    um.reserve(N);
    um.max_load_factor(0.7);
    auto start = chrono::high_resolution_clock::now();
    for(int x : keys) um[x] = x;
    auto mid = chrono::high_resolution_clock::now();
    for(int x : keys) if(um.find(x) == um.end()) cout << "err\n";
    auto end = chrono::high_resolution_clock::now();
    cout << "unordered_map insert: " << chrono::duration<double>(mid-start).count()
         << "s, lookup: " << chrono::duration<double>(end-mid).count() << "s\n";

    // ---------- gp_hash_table ----------
    gp_hash_table<int,int> gp; // chỉ khởi tạo mặc định
    start = chrono::high_resolution_clock::now();
    for(int x : keys) gp[x] = x;
    mid = chrono::high_resolution_clock::now();
    for(int x : keys) if(gp.find(x) == gp.end()) cout << "err\n";
    end = chrono::high_resolution_clock::now();
    cout << "gp_hash_table insert: " << chrono::duration<double>(mid-start).count()
         << "s, lookup: " << chrono::duration<double>(end-mid).count() << "s\n";

    return 0;
}
