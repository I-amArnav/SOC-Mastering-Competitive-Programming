#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e7 + 1;
vector<int> mobius(MAX, 1);
vector<bool> isPrime(MAX, true);

void compute_mobius() {
    for (int i = 2; i < MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i; j < MAX; j += i) {
                mobius[j] *= -1;
                isPrime[j] = false;
            }
            for (ll j = 1LL * i * i; j < MAX; j += 1LL * i * i) {
                mobius[j] = 0;
            }
        }
    }
}

ll count_square_free(ll n) {
    ll res = 0;
    for (ll i = 1; i * i <= n; ++i) {
        res += mobius[i] * (n / (i * i));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compute_mobius();

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << count_square_free(n) << '\n';
    }
}
