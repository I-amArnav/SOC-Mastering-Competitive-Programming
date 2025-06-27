#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll modPow(ll base, ll exp, ll m=MOD) {
    ll res = 1;
    base %= m;
    while (exp > 0) {
        if (exp & 1) 
            res = (res * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> p(n+1);
    for (ll i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    vector<int> spf(n+1);
    for (int i = 0; i <= n; ++i)
        spf[i] = i;
    for (int i = 2; i * i <= n; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    vector<bool> vis(n+1, false);
    vector<ll> cycles;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ll len = 0, u = i;
            while (!vis[u]) {
                vis[u] = true;
                u = p[u];
                ++len;
            }
            cycles.push_back(len);
        }
    }
    map<ll,int> maxExp;
    for (ll len : cycles) {
        ll x = len;
        map<ll,int> localExp;
        while (x > 1) {
            ll prime = spf[x];
            int cnt = 0;
            while (x % prime == 0) {
                x /= prime;
                ++cnt;
            }
            localExp[prime] = cnt;
        }
        for (auto &kv : localExp) {
            maxExp[kv.first] = max(maxExp[kv.first], kv.second);
        }
    }
    ll ans = 1;
    for (auto &kv : maxExp) {
        ans = ans * modPow(kv.first, kv.second) % MOD;
    }
    cout << ans;
}