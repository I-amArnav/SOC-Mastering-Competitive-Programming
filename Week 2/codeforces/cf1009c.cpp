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
        int x,y=0,pow=1;
        cin>>x;
        bool zero=false,one=false;
        int stored=x;
        while(x>0){
            if(x%2==0 && !zero){
                y+=pow;
                zero=true;
            }
            else if(x%2==1 && !one){
                y+=pow;
                one=true;
            }
            if(one && zero){
                break;
            }
            x/=2;
            pow*=2;
        }
        if(!one || !zero || y>=stored){
            cout<<"-1\n";
        }else{
            cout<<y<<"\n";
        }
    }
}