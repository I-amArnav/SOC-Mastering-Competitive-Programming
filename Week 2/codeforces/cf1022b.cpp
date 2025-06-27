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
        ll n,x;
        cin>>n>>x;
        if(n==1 && x==0){
            cout<<"-1"<<"\n";
            continue;
        }
        if(x==0){
            if(n%2==0){
                cout<<n<<"\n";
            }
            else{
                cout<<n+3<<"\n";
            }
            continue;
        }
        if(x==1){
            if(n%2==1){
                cout<<n<<"\n";
            }
            else{
                cout<<n+3<<"\n";
            }
            continue;
        }
        ll ones=0,temp=x;
        while(x>0){
            if(x%2==1){
                ones+=1;
            }
            x=x/2;
        }
        if(n-ones<=0){
            cout<<temp<<"\n";
        }else{
            cout<<temp+n-ones+(n-ones)%2<<"\n";
        }
    }
}