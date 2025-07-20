#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;

ll modpower(ll a, ll b){
    ll r=1;
    a=a%mod;
    while(b>0){
        if(b%2==1){
            r*=a;
            r%=mod;
        }
        b=b/2;
        a=(a*a)%mod;   
    }    
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll a,b,k,n,m;
        cin>>a>>b>>k;
        n=((k*(a-1))%mod+1)%mod;
        m=k*(b-1)%mod;
        for(ll i=0;i<a;i++){
            m*=(n-i+mod)%mod;
            m%=mod;
            m*=modpower((a-i+mod)%mod, mod-2)%mod;
            m%=mod;
        }
        m=(m+1)%mod;
        cout<<n<<" "<<m<<"\n";
    }
}