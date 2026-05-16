#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    const vector<string> COWS = []() {
	    vector<string> temp{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
	    sort(all(temp));
	return temp;
    }();
    const int MAXS = 8;
    unordered_map<string, int> idx;
    idx.reserve(100);
    idx.max_load_factor(0.7);
    for (int i = 0; i < MAXS; ++i) idx[COWS[i]] = i;
    int n; cin >> n;
    vector<vector<int>> adj(MAXS);
    for (int i = 0; i < n; ++i){
        string cow1;
        string cow2;
        string temp;
        cin >> cow1 >> temp >> temp >> temp >> temp >> cow2;
        int idx_cow1 = idx[cow1];
        int idx_cow2 = idx[cow2];
        adj[idx_cow1].push_back(idx_cow2);
        adj[idx_cow2].push_back(idx_cow1);
    }
    vector<int> ans;
    vector<bool> visited(MAXS, false);
    for (int c = 0; c < MAXS; ++c){
        int sz = (int)adj[c].size();
        if (!visited[c] && sz <= 1){
            visited[c] = true;;
            ans.push_back(c);
            if (sz == 1){
                int u = c;
                int v = adj[u][0];
                while ((int)adj[v].size() == 2){
                    visited[v] = true;
                    ans.push_back(v);
                    for (int node : adj[v]){
                        if (node != u){
                            u = v;
                            v = node;
                            break;
                        }
                    }
                }
                visited[v] = true;
                ans.push_back(v);
            }
        }
    }
    for (int c : ans){
        cout << COWS[c] << endl;
    }
    return 0;
}