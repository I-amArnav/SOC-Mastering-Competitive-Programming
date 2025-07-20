#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

//incomplete

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n,l,r,xadd;
        cin>>n>>l>>r;
        map<int,int>a;
        map<int,int>seen;
        for(int i=1;i<=n;i++){
            int temp;cin>>temp;
            a[i]=temp;
            if(i==0){xadd=a[i];}
            else{xadd=xadd^a[i];}
            if(2*i>n){a[2*i]=xadd;}
            if(2*i+1>n){a[2*i+1]=xadd;}
            seen[i]=1;seen[2*i]=1;seen[2*i+1]=1;
        }
        if(l<=2*n+1){cout<<a[l]<<"\n";continue;}
        int till=l/2;
        
    }
}