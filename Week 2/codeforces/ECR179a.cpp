#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll x,a=1,b=2,n=0;
        cin>>x;
        if(x==1){
            cout<<"3\n";
            continue;
        }
        while(true){
            n+=2;
            if(a>=x){
                n+=2;
                break;
            }else if(b>=x){
                n+=4;
                break;
            }
            a=2*a+1;
            b=2*b+1;
        }
        cout<<n-1<<"\n";
    }
}