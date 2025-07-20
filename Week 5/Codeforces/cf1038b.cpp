#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll ans=0,a,b,c,d;
        int n;cin>>n;
        fori(n){
            cin>>a>>b>>c>>d;
            if(b>d){ans+=a+b-d;}
            else if(a>c){ans+=a-c;}
        }
        cout<<ans<<'\n';
    }
}