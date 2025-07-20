#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
vector<ll>f(46,0);
void initfibonacci(){
    f[0]=1;
    f[1]=1;
    for(int i=2;i<46;i++){
        f[i]=f[i-1]+f[i-2];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    initfibonacci();
    while(t--){
        int n,x,y;
        cin>>n>>y>>x;
        ll l=f[n+1],h=f[n];
        bool valid=false;
        while(true){
            if(l==x && h==y){
                valid=true;
                break;
            }
            if(x>l || y>h){break;}
            if(x>h){x-=h;}
            l-=h;
            swap(l,h);
            swap(x,y);
        }
        if(valid){cout<<"YES";}
        else{cout<<"NO";}
        cout<<"\n";
    }
}