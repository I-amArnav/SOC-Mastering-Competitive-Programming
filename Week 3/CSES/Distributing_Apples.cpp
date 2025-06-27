#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5;
vector<ll> fact(MAX), invFact(MAX);

ll binpow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute(){
    fact[0] = 1;
    for(int i = 1; i < MAX; ++i)
        fact[i] = fact[i-1] * i % MOD;
    
    invFact[MAX - 1] = binpow(fact[MAX - 1], MOD - 2);
    for(int i = MAX - 2; i >= 0; --i)
        invFact[i] = invFact[i+1] * (i+1) % MOD;
}

ll nCr(int n, int r){
    if(r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    precompute();
    cout << nCr(n + m - 1, m);
}