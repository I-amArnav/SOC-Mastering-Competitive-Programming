#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,q,l,r,ans=0;
    cin>>n>>q;
    vector<ll>v(n),vec(n,0);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    while(q--){
        cin>>l>>r;
        vec[l-1]+=1;
        if(r<n){
            vec[r]-=1;
        }
    }
    for(ll i=1;i<n;i++){
        vec[i]+=vec[i-1];
    }
    sort(v.begin(),v.end());
    sort(vec.begin(),vec.end());
    for(ll i=0;i<n;i++){
        ans+=v[i]*vec[i];
    }
    cout<<ans;
}