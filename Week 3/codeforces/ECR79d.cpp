#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int MAX = 1e6 + 7;

ll add(ll a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
    return a;
}
ll mul(ll a, ll b) {
    return a * b % MOD;
}
ll powmod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> cnt(MAX, 0);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }
    ll inv_n = powmod(n, MOD - 2);
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        ll inv_size = powmod((int)a[i].size(), MOD - 2);
        for (int x : a[i]) {
            ll contrib = mul(mul(inv_n, inv_size), mul(cnt[x], inv_n));
            ans = add(ans, contrib);
        }
    }

    cout << ans << "\n";
    return 0;
}