#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
#define all(v) v.begin(),v.end()
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,d;
        cin>>n>>m>>d;
        vector<int>p(n+1),a(m),pos(n+1);
        fori(n){cin>>p[i+1];pos[p[i+1]]=i+1;}
        fori(m){cin>>a[i];}
        int ans=2e5+5;
        fori(m-1){
            int p1=pos[a[i]],p2=pos[a[i+1]];
            int dist=p2-p1;
            if(dist<=0 || dist>d){ans=0;break;}
            ans=min(ans,dist);
            if(d+1-dist<=n-p2+p1-1){ans=min(ans,d+1-dist);}
        }
        cout<<ans<<'\n';
    }
}