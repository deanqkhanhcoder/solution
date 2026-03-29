#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;
    int s1 = n / 2;
    int s2 = n - s1;
    vector<ll> sub1;
    sub1.reserve(1 << s1);
    for (int mask = 0; mask < (1 << s1); ++mask)
    {
        ll sum = 0;
        for (int i = 0; i < s1; ++i)
        {
            if (mask & (1 << i))
                sum += a[i];
        }
        sub1.push_back(sum);
    }
    vector<ll> sub2;
    for (int mask = 0; mask < (1 << s2); ++mask)
    {
        ll sum = 0;
        for (int i = 0; i < s2; ++i)
        {
            if (mask & (1 << i))
                sum += a[s1 + i];
        }
        sub2.push_back(sum);
    }
    ll sum = sub1.back() + sub2.back();
    sort(sub2.begin(), sub2.end());
    sub2.erase(unique(sub2.begin(), sub2.end()), sub2.end());
    ll ans = LLONG_MAX;
    for (ll s : sub1)
    {
        ll t = sum / 2 - s;
        auto idx = lower_bound(sub2.begin(), sub2.end(), t);
        if (idx != sub2.end())
        {
            ll curr = s + *idx;
            ans = min(ans, llabs(sum - 2 * curr));
        }
        if (idx != sub2.begin())
        {
            idx--;
            ll curr = s + *idx;
            ans = min(ans, llabs(sum - 2 * curr));
        }
    }
    cout << ans;
    return 0;
}