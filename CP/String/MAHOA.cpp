#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
string s;
vector<pair<char, ll>> adj;
void data(){
    int n = s.size();
    int i = 0;
    while (i < n){
        char c = s[i++];
        ll num = 0;
        while (i < n && isdigit(s[i])) num = num * 10 + s[i++] - '0';
        adj.push_back({c, num});
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k; cin >> k;
    cin >> s;
    ll k1 = k;
    data();
    vector<pair<char, ll>> st;
    for (auto &p : adj){
        char c = p.first;
        ll cnt = p.second;
        while (!st.empty() && k > 0 && st.back().first < c){
            ll take = min(k, st.back().second);
            st.back().second -= take;
            k -= take;
            if (st.back().second == 0) st.pop_back();
        }
        if (!st.empty() && st.back().first == c){
            st.back().second += cnt;
            continue;
        }
        st.push_back({c, cnt});
    }
    while (k > 0 && !st.empty()){
        if (st.back().second <= k){
            k -= st.back().second;
            st.pop_back();
        } else {
            st.back().second -= k;
            break;
        }
    }
    for (auto &p : st){
        cout << p.first << p.second;
    }
    cout << '\n';
    st.clear();
    for (auto &p : adj){
        char c = p.first;
        ll cnt = p.second;
        while (!st.empty() && k1 > 0 && st.back().first > c){
            ll take = min(k1, st.back().second);
            st.back().second -= take;
            k1 -= take;
            if (st.back().second == 0) st.pop_back();
        }
        if (!st.empty() && st.back().first == c){
            st.back().second += cnt;
            continue;
        }
        st.push_back({c, cnt});
    }
    while (k1 > 0 && !st.empty()){
        if (st.back().second <= k1){
            k1 -= st.back().second;
            st.pop_back();
        } else {
            st.back().second -= k1;
            break;
        }
    }
    for (auto &p : st){
        cout << p.first << p.second;
    }
    return 0;
}