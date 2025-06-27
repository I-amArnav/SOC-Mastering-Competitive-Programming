#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 1;
vector<ll> der(MAX);

void precompute() {
    der[0] = 1;
    der[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        der[i] = (i - 1) * (der[i - 1] + der[i - 2]) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    precompute();
    cout << der[n] << "\n";
    return 0;
}
