#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nC2(ll n){
    return n*(n-1)/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,m,ans1=0,ans2=0;
    cin>>n>>m;
    ans1=nC2(n-m+1);
    for(ll i=0;i<n%m;i++){
        ans2+=nC2(n/m+1);
    }
    for(ll i=0;i<m-n%m;i++){
        ans2+=nC2(n/m);
    }
    cout<<min(ans1,ans2)<<" "<<max(ans1,ans2);
}