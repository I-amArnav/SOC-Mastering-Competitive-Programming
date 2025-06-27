#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(ll k){
    ll c=0;
    while(k>0){
        c++;
        k/=2;
    }
    return c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        map<ll,ll> m;
        ll n;
        ll count=0;
        cin>>n;
        vector<ll>a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
            m[func(a[i])]++;
        }
        for(auto [p,n] : m){
            count+=n*(n-1)/2;
        }
        cout<<count<<"\n";
    }
}