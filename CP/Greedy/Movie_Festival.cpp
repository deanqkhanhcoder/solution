#include <bits/stdc++.h>
using namespace std;
struct Movie {
    int start, end;
};

void radix_sort(vector<Movie>& movies) {
    const int B = 20;
    const int MASK = (1 << B) - 1;
    int n = movies.size();
    vector<Movie> tmp(n);
    for (int pass = 0; pass < 2; pass++) {
        vector<int> cnt(1 << B, 0);
        for (int i = 0; i < n; i++) {
            int key = (movies[i].end >> (B * pass)) & MASK;
            cnt[key]++;
        }
        for (int i = 1; i < (1 << B); i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            int key = (movies[i].end >> (B * pass)) & MASK;
            tmp[--cnt[key]] = movies[i];
        }

        movies.swap(tmp);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Movie> movies(n);
    for (int i = 0; i < n; i++) cin >> movies[i].start >> movies[i].end;
    radix_sort(movies);
    int ans = 0;
    int last_end = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].start >= last_end) {
            ans++;
            last_end = movies[i].end;
        }
    }

    cout << ans;
}
