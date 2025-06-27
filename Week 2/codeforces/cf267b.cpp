#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ones(int n){
    int count=0;
    while(n>0){
        if(n%2){count+=1;}
        n/=2;
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,k,count=0;
    cin>>n>>m>>k;
    int p[m+1];
    for(int i=0;i<m+1;i++){
        cin>>p[i];
    }
    for(int i=0;i<m;i++){
        int temp=p[i]^p[m];
        if(ones(temp)<=k){
            count+=1;
        }
    }
    cout<<count;
}