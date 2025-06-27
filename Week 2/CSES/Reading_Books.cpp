#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,sum=0;
    cin>>n;
    vector<ll>tim(n);
    for(ll i=0;i<n;i++){
        cin>>tim[i];
        sum+=tim[i];
    }
    sort(tim.begin(),tim.end());
    if(2*tim[n-1]>sum){
        cout<<2*tim[n-1];
    }else{
        cout<<sum;
    }
}