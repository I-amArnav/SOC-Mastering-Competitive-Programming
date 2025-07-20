#include<bits/stdc++.h>
using namespace std;
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
typedef long long ll;
const ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>a(n),next(n,n);
    fori(n){cin>>a[i];}
    for(int i=n-2;i>=0;i--){
        if(a[i]==a[i+1]){
            next[i]=next[i+1];
        }
        else{
            next[i]=i+1;
        }
    }
    while(m--){
        int l,r,x;
        cin>>l>>r>>x;
        l--;r--;
        if(a[l]!=x){cout<<l+1<<endl;}
        else{
            l=next[l];
            if(l<n && l<=r){
                cout<<l+1<<endl;
            }else{cout<<"-1\n";}
        }
    }
}