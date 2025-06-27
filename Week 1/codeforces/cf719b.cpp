#include<bits/stdc++.h>
using namespace std;
int consec(int n,int digit){
    int ans=0,temp=1;
    for(int i=1;i<=digit;i++){
        ans+=n*temp;
        temp*=10;
    }
    return ans;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        int count=0;
        cin>>n;
        int i=10,log10=1;
        while(n>=i){
            count+=9;
            i*=10;
            log10+=1;
        }
        for(int j=1;j<10;j++){
            if(n>=consec(j,log10)){
                count+=1;
            }
            else{
                break;
            }
        }
        cout<<count<<endl;
    }
}