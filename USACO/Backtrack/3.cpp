#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
unordered_set<int> way;
void dfs(int day, int a_milk, unordered_multiset<int> a, int b_milk, unordered_multiset<int> b){
    if (day == 4){
        way.insert(a_milk);
        return;
    }
    for (auto it = a.begin(); it != a.end(); ++it){
        int milk = *it;
        unordered_multiset<int> new_a = a;
        new_a.erase(new_a.find(milk));
        unordered_multiset<int> new_b = b;
        new_b.insert(milk);
        dfs(day + 1, b_milk + milk, new_b, a_milk - milk, new_a);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    unordered_multiset<int> a;
    a.reserve(20);
    a.max_load_factor(0.7);
    for (int i = 0; i < 10; ++i){
        int first; cin >> first;
        a.insert(first);
    }
    unordered_multiset<int> b;
    b.reserve(20);
    b.max_load_factor(0.7);
    for (int i = 0; i < 10; ++i){
        int second; cin >> second;
        b.insert(second);
    }
    dfs(0, 1000, a, 1000, b);
    cout << way.size();
}