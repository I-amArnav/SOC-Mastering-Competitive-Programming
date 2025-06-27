#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll n,k,ans=1;
        cin>>n>>k;
        n=n;
        for(ll i=0;i<k;i++){
            ans=(ans*n)%mod;
            if(ans<0){
                ans+=mod;
            }
        }
        cout<<ans<<"\n";
    }
}