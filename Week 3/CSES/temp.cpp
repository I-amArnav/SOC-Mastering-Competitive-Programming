#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll mod = 1e9 + 7;

ll binpow(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, mod - 2);
}

ll mulmod(ll a, ll b) {
    return (a % mod) * (b % mod) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> prime(n), power(n);

    ll numDivisors = 1;      
    ll exponentMod = 1;
    for (int i = 0; i < n; i++) {
        cin >> prime[i] >> power[i];
        numDivisors = mulmod(numDivisors, power[i] + 1);
        exponentMod = (exponentMod * (power[i] + 1)) % (mod - 1);
    }

    ll sumDivisors = 1;
    ll productDivisors = 1;

    for (int i = 0; i < n; i++) {

        if (numDivisors % 2 == 1) {
            ll exp = (power[i] * (exponentMod - 1) / 2) % (mod - 1);
            productDivisors = mulmod(productDivisors, prime[i]);
            productDivisors = mulmod(productDivisors, binpow(prime[i], exp));
        } else {
            ll exp = (power[i] * (exponentMod / 2)) % (mod - 1);
            productDivisors = mulmod(productDivisors, binpow(prime[i], exp));
        }
        ll numerator = (binpow(prime[i], power[i] + 1) - 1 + mod) % mod;
        ll denominator = inv(prime[i] - 1);
        sumDivisors = mulmod(sumDivisors, mulmod(numerator, denominator));
    }

    cout << numDivisors << " " << sumDivisors << " " << productDivisors << "\n";

    return 0;
}//incomplete
