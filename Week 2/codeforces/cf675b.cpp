#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll n,m,count=0;
        cin>>n>>m;
        ll a[n][m];
        vector<ll>temp(3,0);
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        for(ll i=0;i<(n+1)/2;i++){
            for(ll j=0;j<(m+1)/2;j++){
                vector<int>v;
                v.push_back(a[i][j]);
                if(2*i!=n-1){
                    v.push_back(a[n-1-i][j]);
                }
                if(2*j!=m-1){
                    v.push_back(a[i][m-1-j]);
                }
                if(2*i!=n-1 && 2*j!=m-1){
                    v.push_back(a[n-1-i][m-1-j]);
                }
                sort(v.begin(),v.end());
                ll median=v[v.size()/2];
                for(auto x:v){
                    count+=abs(x-median);
                }
            }
        }
        cout<<count<<endl;
    }
}