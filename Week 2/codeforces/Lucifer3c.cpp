#include<bits/stdc++.h>
using namespace std;

int main(){
    long long x,y,z,k,best=0;
    cin>>x>>y>>z>>k;
    for(long long i=0;i<=min(k,x-1);i++){
        for(long long j=0;j<=min(k-i,y-1);j++){
            if(k-i-j>z-1){
                continue;
            }
            long long temp = (i+1)*(j+1)*(k-i-j+1);
            if(temp>best){
                best=temp;
            }
        }
    }
    cout<<best;
}