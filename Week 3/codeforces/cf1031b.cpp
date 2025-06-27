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
        int w,h,a,b,x1,y1,x2,y2;
        cin>>w>>h>>a>>b>>x1>>y1>>x2>>y2;
        if(abs(x2-x1)==0){
            if(abs(y2-y1)%b==0){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }else if(abs(y2-y1)==0){
            if(abs(x2-x1)%a==0){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }else if(abs(x2-x1)%a==0){
            cout<<"YES\n";
        }else if(abs(y2-y1)%b==0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}