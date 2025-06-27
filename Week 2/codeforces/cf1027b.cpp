#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,ones=0,zeros=0;
        string s;
        cin>>n>>k>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zeros+=1;
            }
            else{
                ones+=1;
            }
        }
        if(ones%2==1){
            n-=2;
            ones-=1;
            zeros-=1;
        }
        if(ones>=n/2-k && zeros>=n/2-k && (n/2-k)%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}