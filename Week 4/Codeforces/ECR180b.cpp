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
        int n;
        cin>>n;
        bool already=false;
        vector<int>a(n);
        fori(n){
            cin>>a[i];
            if(i!=0){
                if(abs(a[i]-a[i-1])<=1){already=true;}
            }
        }
        if(already){cout<<"0\n";continue;}
        if(n==2){cout<<"-1\n";continue;}
        already=false;
        for(int i=0;i<n-2;i++){
            if(((a[i]-a[i+1]>0)&&(a[i+2]-a[i+1]>0))||((a[i]-a[i+1]<0)&&(a[i+2]-a[i+1]<0))){
                cout<<"1\n";
                already=true;
                break;
            }
        }
        if(!already){
            cout<<"-1\n";
        }
    }
}