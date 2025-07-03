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
        int n,s,dx,dy,x,y,count=0;
        cin>>n>>s;
        fori(n){
            cin>>dx>>dy>>x>>y;
            if(dx==dy){
                if(x==y){
                    count++;
                }
            }else{
                if(x+y==s){
                    count++;
                }
            }
        }
        cout<<count<<"\n";
    }
}