#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
#define all(v) v.begin(),v.end()
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int a,b,x,y;
        ll cost=0;
        cin>>a>>b>>x>>y;
        if(a==b){cout<<"0\n";continue;}
        if(b<a){
            if(a%2 && b==a-1){
                cout<<y<<'\n';
                continue;
            }else{
                cout<<"-1\n";
                continue;
            }
        }
        if((b-a)%2){
            cost+= (a%2 ? x:min(x,y));
            a++;
        }
        cost+= (b-a)*(min(x,y)+x)/2;
        cout<<cost<<'\n';
    }
}