#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
ll mod=1e9+7;

ll binpow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll inv(ll a){
    return binpow(a, mod - 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    ll num=1,sum=1,product=1,num_exp=1;
    cin>>n;
    vector<ll> prime(n),pow(n);
    for(int i=0;i<n;i++){
        cin>>prime[i]>>pow[i];
        num=(num*(pow[i]+1))%mod;
        num_exp=(num_exp*(pow[i]+1))%(mod-1);
    }
    for(int i=0;i<n;i++){
        if(num % 2){
            product = (product * prime[i] * binpow(prime[i], (pow[i]*(num_exp - 1) / 2)%(mod-1))) % mod;
        }else{
            product = product * binpow(prime[i], (pow[i]*num_exp/2)%(mod-1)) % mod;
        }
        ll numerator = (binpow(prime[i], (pow[i] + 1)%(mod-1)) - 1 + mod) % mod;
        ll denominator = inv(prime[i] - 1);
        sum = sum * numerator % mod * denominator % mod;
    }
    cout<<num<<" "<<sum<<" "<<product;
}
//incomplete