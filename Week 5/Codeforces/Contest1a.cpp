#include<bits/stdc++.h>
using namespace std;
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
typedef long long ll;
const ll mod=1e9+7;

int main(){
    int t;cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<min({a,b,(a+b)/4})<<endl;
    }
}