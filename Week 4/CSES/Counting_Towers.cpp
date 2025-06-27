#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
vector<ll>join(1e6+1,0),nojoin(1e6+1,0);

void update(int n){
    if(join[n] && nojoin[n]){
        return;
    }
    update(n-1);
    join[n]=((2*join[n-1])%mod+nojoin[n-1])%mod;
    nojoin[n]=(join[n-1]+(4*nojoin[n-1])%mod)%mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    join[1]=1;nojoin[1]=1;
    while(t--){
        int n;cin>>n;
        update(n);
        cout<<(join[n]+nojoin[n])%mod<<"\n";
    }
}