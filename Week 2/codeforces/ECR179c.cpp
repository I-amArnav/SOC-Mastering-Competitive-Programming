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
        ll n,f=1;
        cin>>n;
        vector<ll>a(n);
        map<ll,ll>freq;
        bool allequal=true;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(i==0){
                f=1;
                freq[a[i]]=1;
                continue;
            }
            if(a[i]!=a[i-1]){
                allequal=false;
                f=1;
            }
            else{
                f+=1;
            }
            if(f>freq[a[i]]){
                freq[a[i]]=f;
            }
        }
        if(allequal){
            cout<<"0\n";
            continue;
        }
        ll best=-1;
        for(auto [e,f]:freq){
            if(best==-1){
                best=e*(n-f);
            }
            else if(e*(n-f)<best){
                best=e*(n-f);
            }
        }
        cout<<best<<"\n";
    }
}