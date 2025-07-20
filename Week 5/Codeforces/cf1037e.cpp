#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
ll lcm(ll x,ll y){
    return x*y/gcd(x,y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll>p(n),s(n),a(n);
        bool valid=true;
        fori(n){
            cin>>p[i];
            if(i==0 || valid){continue;}
            if(p[i-1]%p[i]!=0){valid=false;}
        }
        fori(n){
            cin>>s[i];
            a[i]=lcm(p[i],s[i]);
            if(i==0 || valid){continue;}
            if(s[i]%s[i-1]!=0){valid=false;}
        }
        if(!valid || p[n-1]!=s[0]){
            cout<<"NO\n";
            continue;
        }
        int g=0;
        fori(n){
            g=gcd(g,a[i]);
            if(g!=p[i]){valid=false;break;}
        }
        g=0;
        for(int i=n-1;i>=0;i--){
            g=gcd(a[i],g);
            if(g!=s[i]){valid=false;break;}
        }
        if(valid){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }
}