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
        int n,k,ones=0;
        cin>>n>>k;
        string s;cin>>s;
        fori(n){
            if(s[i]=='1'){ones++;}
        }
        if(ones<=k){cout<<"ALICE\n";}
        else if(n<2*k){cout<<"ALICE\n";}
        else{cout<<"BOB\n";}
    }
}