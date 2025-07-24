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
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>b(n);
        ll x;
        fori(n){
            cin>>b[i];
            if(i==0){continue;}
            ll temp=b[i-1]/gcd(b[i-1],b[i]);
            if(i==1){x=temp;}
            else{
                x=temp*x/gcd(temp,x);
            }
        }
        cout<<x<<endl;
    }
}