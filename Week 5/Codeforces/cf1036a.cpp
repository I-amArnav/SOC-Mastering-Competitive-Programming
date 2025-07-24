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
        int n,idx;cin>>n;
        vector<int>a(n);
        bool valid=false;
        fori(n){
            cin>>a[i];
            if(i==0 || valid){continue;}
            if(a[i-1]>a[i]){valid=true;idx=i-1;}
        }
        if(n==1 || !valid){cout<<"NO\n";continue;}
        cout<<"YES\n2\n"<<a[idx]<<" "<<a[idx+1]<<"\n";
    }
}