#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,x,first=-1,last=-1;
        cin>>n>>x;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1){
                if(first==-1){first=i;}
                last=i;
            }
        }
        if(x>=last-first+1){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}