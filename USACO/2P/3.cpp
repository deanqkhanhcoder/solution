#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
constexpr int MAXA = 26 * 2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("TASK.inp", "r", stdin);
    // freopen("TASK.out", "w", stdout);
    int n; cin >> n;
    string s; cin >> s;
    bitset<MAXA> has;
    for (char c : s){
        if ('a' <= c && c <= 'z') has[c - 'a'] = 1;
        else has[26 + (c - 'A')] = 1;
    }
    vector<int> cnt(MAXA, 0);
    auto check = [&](){
        for (int i = 0; i < MAXA; i++){
            if (has[i] && cnt[i] == 0){
                return false;
            }
        }
        return true;
    };
    auto get = [](char c){
        return ('a' <= c && c <= 'z' ? c - 'a' : 26 + (c - 'A'));
    };
    int r = 0;
    for (; r < n; ++r){
        char c = s[r];
        int idx = get(c);
        cnt[idx]++; 
        if (check()) break;
    }
    int ans = r + 1;
    int started = r;
    int l = 0;
    for (; r < n; ++r){
    if (r != started) cnt[get(s[r])]++;
    while (l < r && cnt[get(s[l])] > 1){
        cnt[get(s[l])]--;
        l++;
        ans = min(ans, r - l + 1);
        }
    }
    cout << ans;
}