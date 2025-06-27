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
        ll n,to_add,count=0;
        cin>>n;
        bool take=true;
        while(n>0){
            if(n%2==0){
                if(n%4==0 && n!=4){
                    to_add=1;
                }
                else{
                    to_add=n/2;
                }
                if(take){
                    count+=to_add;
                    take=false;
                }
                else{
                    take=true;
                }
                n-=to_add;
            }
            else{
                if(take){
                    count+=1;
                    take=false;
                }
                else{
                    take=true;
                }
                n-=1;
            }
        }
        cout<<count<<"\n";
    }
}