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
        int n,px,qx,py,qy;
        cin>>n>>px>>py>>qx>>qy;
        ll mini=0,maxi=0;
        vector<int>a(n);
        fori(n){
            cin>>a[i];
            maxi+=a[i];    
        }
        sort(all(a));
        reverse(all(a));
        if(maxi>=2*a[0]){mini=0;}
        else{mini=2*a[0]-maxi;}
        maxi*=maxi;
        mini*=mini;
        ll dist=1LL*(px-qx)*(px-qx)+1LL*(py-qy)*(py-qy);
        if(dist>=mini && dist<=maxi){
            cout<<"Yes\n";
        }else{cout<<"No\n";}
    }
}