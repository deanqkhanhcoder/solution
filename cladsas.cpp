#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    unordered_map<int, vector<int>> pos;
    pos.reserve(n * 2);
    for (int i = 1; i <= n; ++i){
        int a; cin >> a;
        pos[a].push_back(i);
    }
    vector<int> dou;
    dou.reserve(2);
    for (auto &p : pos){
        if (p.second.size() >= 4){
            for (int i = 0; i < 4; ++i){
                cout << p.second[i] << ' ';
            }
            return 0;
        }
        if (p.second.size() >= 2){
            dou.push_back(p.first);
            if ((int)dou.size() == 2){
                int x = dou[0], y = dou[1];
                cout << pos[x][0] << ' ' << pos[y][0] << ' ';
                cout << pos[x][1] << ' ' << pos[y][1] << ' ';
                return 0;
            }
        }
    }
    vector<pair<int,int>> other; 
    other.reserve(3000);
    other.push_back({0, 0});
    for (auto &p : pos){
        other.push_back({p.second[0], p.first});
        if ((int)other.size() == 3000) break;
    }
    int m = min((int)other.size(), 3000);
    unordered_map<int, pair<int,int>> ok;
    ok.reserve(m * m / 2);
    for (int i = 1; i <= m; ++i){
        for (int j = i + 1; j <= m; ++j){
            int s = other[i].second + other[j].second;
            if (!ok.count(s)){
                ok[s] = {other[i].first, other[j].first};
            } else {
                if (ok[s].second < i){
                    cout << other[i].first << ' ' << other[i].second << ' ';
                    cout << ok[s].first << ' ' << ok[s].second << ' ';
                    return 0;
                }
            }
        }
    }
    cout << -1;
    return 0;
}