#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
#define all(v) v.begin(),v.end()
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll n,l,r,k;
        cin>>n>>l>>r>>k;
        if(n%2){cout<<l<<'\n';continue;}
        if(n==2){cout<<"-1\n";continue;}
        ll res=1;
        while(res<=l){res*=2;}
        if(res>r){cout<<"-1\n";continue;}
        if(k<=n-2){cout<<l;}
        else{cout<<res;}
        cout<<'\n';
    }
}