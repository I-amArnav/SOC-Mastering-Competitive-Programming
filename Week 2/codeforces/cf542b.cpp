#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,temp,p1,p2,t1,t2,dist=0;
    cin>>n;
    map<ll,ll> pos1,pos2;
    for(ll i=1;i<=2*n;i++){
        cin>>temp;
        if(pos1[temp]){
            pos2[temp]=i;
        }
        else{
            pos1[temp]=i;
        }
    }
    dist+=pos1[1]+pos2[1]-2;
    for(ll temp=2;temp<=n;temp++){
        p1=pos1[temp-1];
        p2=pos2[temp-1];
        t1=pos1[temp];
        t2=pos2[temp];
        dist+=min(abs(t1-p1)+abs(t2-p2),abs(t1-p2)+abs(t2-p1));
    }
    cout<<dist<<endl;
}