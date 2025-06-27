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
        ll x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        ll num=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
        if(num>0){
            cout<<"LEFT";
        }else if(num<0){
            cout<<"RIGHT";
        }else{
            cout<<"TOUCH";
        }
        cout<<"\n";
    }
}