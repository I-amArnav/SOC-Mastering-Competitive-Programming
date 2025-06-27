#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    if(n==1){cout<<"1";return 0;}
    if(n<=3){cout<<"NO SOLUTION";return 0;}
    if(n==4){
        cout<<"3 1 4 2";
        return 0;
    }
    int i1=1,i2=n-n/2+1;
    for(int i=0;i<n;i++){
        if(i%2==0){
            cout<<i1<<" ";
            i1++;
        }else{
            cout<<i2<<" ";
            i2++;
        }
    }
}