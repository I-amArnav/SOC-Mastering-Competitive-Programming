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
        string s;cin>>s;
        int n=s.size();
        ll total=0;
        map<int,vector<int>>m;
        vector<int>balance(n+1,0);
        m[0].push_back(0);
        fori(n){
            balance[i+1]=balance[i]+(s[i]=='1'?1:-1);
            m[balance[i+1]].push_back(i+1);
        }
        for(auto [val,vec]:m){
            int sz=vec.size();
            vector<ll>prefix(sz+1,0);
            fori(sz){
                prefix[i+1]=(prefix[i]+vec[i]+1)%mod;
            }
            fori(sz){
                int y=vec[i];
                ll contrib=prefix[i]*(n-y+1)%mod;
                total=(total+contrib)%mod;
            }
        }
        cout<<total<<"\n";
    }
}