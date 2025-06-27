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
    ll n;
    cin>>n;
    vector<ll>arr(n+6,0);
    arr[0]=1;arr[1]=1;arr[2]=2;arr[3]=4;arr[4]=8;arr[5]=16;arr[6]=32;
    if(n<=6){cout<<arr[n]<<"\n";}
    else{
        int i=7;
        while(i<=n){
            arr[i]=((2*arr[i-1])%mod-arr[i-7]+mod)%mod;
            i++;
        }
        cout<<arr[n]<<"\n";
    }
}