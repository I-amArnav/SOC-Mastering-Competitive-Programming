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
        int n,j,k;
        cin>>n>>j>>k;
        vector<int>a(n);
        fori(n){cin>>a[i];}
        int player=a[j-1];
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        if(a[0]==player){
            cout<<"YES\n";
        }else if(k!=1){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}