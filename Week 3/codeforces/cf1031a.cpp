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
        int k,a,b,x,y,ans=0;
        cin>>k>>a>>b>>x>>y;
        if(x<y){
            if(k>=a){
                ans+=(k-a)/x+1;
                k-=ans*x;
            }
            if(k>=b){
                ans+=(k-b)/y+1;
            }
        }
        else{
            if(k>=b){
                ans+=(k-b)/y+1;
                k-=ans*y;
            }
            if(k>=a){
                ans+=(k-a)/x+1;
            }
        }
        cout<<ans<<endl;
    }
}