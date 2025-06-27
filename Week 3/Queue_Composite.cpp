#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
ll mod=998244353;

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
    int q,start=0;
    ll A=1,B=0;
    cin>>q;
    vector<pair<ll,ll>>v;
    for(int i=0;i<q;i++){
        int query;
        cin>>query;
        if(query==0){
            ll a,b;
            cin>>a>>b;
            v.push_back({a,b});
            A=(a*A)%mod;
            B=(B*a+b)%mod;
        }else if(query==1){
            ll a=v[start].first,b=v[start].second;
            A=(A*inv(a))%mod;
            B=(B-A*b+mod)%mod;
            start++;
        }else{
            ll x;
            cin>>x;
            cout<<(A*x+B)%mod<<"\n";
        }
    }
}