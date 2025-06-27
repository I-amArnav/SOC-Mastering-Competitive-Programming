#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
ll mod = 1000000007;

ll pow(ll a,ll b){
    if(a==0LL && b==0LL){return 1LL;}
    if(a==0 || a==1){return a;}
    ll ans=1;
    for(int i=0;i<b;i++){
        ans=(ans*a)%mod;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        cout<<pow(a,pow(b,c))<<"\n";
    }
}