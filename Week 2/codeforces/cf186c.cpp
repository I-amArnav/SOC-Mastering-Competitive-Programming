#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,sum=0,power=0;
    cin>>n;
    vector<ll>v(n),level(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
        level[i]=power+1;
        if(i+1==pow(4,power)){
            power+=1;
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(ll i=0;i<n;i++){
        sum+=v[i]*(level[n-1]-level[i]+1);
    }
    cout<<sum<<endl;
}