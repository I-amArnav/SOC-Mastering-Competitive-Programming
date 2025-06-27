#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2) res = res * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}

ll inv(ll a, ll mod) {
    return pow(a, mod - 2, mod);
}

vector<pair<ll, ll>> factorize(ll a) {
    vector<pair<ll, ll>> factors;
    for (ll p = 2; p * p <= a; ++p) {
        if (a % p == 0) {
            ll count = 0;
            while (a % p == 0) {
                a /= p;
                ++count;
            }
            factors.push_back({p, count});
        }
    }
    if (a > 1) factors.push_back({a, 1});
    return factors;
}

int main() {
    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);
    ll A, B;
    cin >> A >> B;

    if (B == 0) {
        cout << 1 << endl;
        return 0;
    }

    vector<pair<ll, ll>> factors = factorize(A);
    ll result = 1;

    for (auto [p, e] : factors) {
        ll numerator = pow(p, e*B + 1, MOD) - 1;
        if (numerator < 0) numerator += MOD;
        ll denominator = inv(p - 1, MOD);
        ll term = numerator * denominator % MOD;
        result = result * term % MOD;
    }

    cout << result << endl;
    return 0;
}