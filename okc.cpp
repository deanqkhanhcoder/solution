#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string s;
int pos;
vector<vector<ll>> a;

ll eval();

/* parse A1..Z9 */
ll parseCell() {
    int col = s[pos] - 'A'; pos++;
    int row = s[pos] - '1'; pos++;
    return a[row][col];
}

ll parseFunc() {
    string name;
    while (isalpha(s[pos])) name += s[pos++];

    pos++; // '('

    vector<ll> args;
    while (true) {
        args.push_back(eval());
        if (s[pos] == ',') pos++;
        else break;
    }

    pos++; // ')'

    if (name == "SUM") {
        ll res = 0;
        for (ll x : args) res += x;
        return res;
    }
    if (name == "MAX") {
        return *max_element(args.begin(), args.end());
    }
    return 0;
}

ll eval() {
    if (isupper(s[pos]) && isdigit(s[pos + 1])) {
        return parseCell();
    }
    return parseFunc();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    a.assign(m, vector<ll>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int q; cin >> q;
    while (q--){
        pos = 0;
        cin >> s;
        cout << eval() << '\n';
    }
}