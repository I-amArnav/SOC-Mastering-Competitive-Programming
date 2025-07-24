#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
#define all(v) v.begin(),v.end()
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        ll count=0;
        vector<ll>a(n);
        fori(n){cin>>a[i];}
        ll comp=a[n-1];
        for(int i=n-2;i>=0;i--){
            if(a[i]<=comp){comp=a[i];continue;}
            ll parts=(a[i]+comp-1)/comp;
            count+=parts-1;
            comp=a[i]/parts;

        }
        cout<<count<<'\n';
    }
}