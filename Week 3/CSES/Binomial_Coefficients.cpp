#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll fact[MAX], invFact[MAX];

ll binpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void func() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAX - 1] = binpow(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

ll binom(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    func();
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << binom(a, b) << "\n";
    }
}
