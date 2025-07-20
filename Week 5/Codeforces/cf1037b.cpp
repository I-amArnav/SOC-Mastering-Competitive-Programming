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
        int n,k,count=0;
        cin>>n>>k;
        vector<int>a(n),cons(n);
        fori(n){cin>>a[i];cons[i]=1-a[i];}
        for(int i=n-2;i>=0;i--){
            if(cons[i]==0){continue;}
            cons[i]+=cons[i+1];
        }
        int i=0;
        while(i<n){
            while(i<n && cons[i]<k){i++;}
            if(i>=n){break;}
            count++;
            i+=(k+1);
        }
        cout<<count<<'\n';
    }
}