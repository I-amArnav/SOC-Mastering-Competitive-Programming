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
        int n,mini=1e9+1;cin>>n;
        vector<int>a(n);
        fori(n){
            cin>>a[i];
            mini=min(mini,a[i]);
        }
        if(a[0]==mini){
            cout<<"Bob";
        }else{cout<<"Alice";}
        cout<<'\n';
    }
}