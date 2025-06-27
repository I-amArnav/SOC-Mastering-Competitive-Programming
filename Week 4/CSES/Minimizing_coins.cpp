#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e6+1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<ll>coin(n),sum(x+1);
    fori(n){cin>>coin[i];}
    sum[0]=0;
    for(int i=1;i<=x;i++){
        sum[i]=mod;
        for(auto c : coin){
            if(i-c>=0){
                sum[i]=min(sum[i],sum[i-c]+1);
            }
        }
    }
    if(sum[x]==mod){cout<<"-1";}
    else{cout<<sum[x];}
}