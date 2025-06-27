#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long a[n];
    bool counted[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        counted[i]=false;
    }
    int count=0;
    for(int i=0;i<n;i++){
        counted[a[i]-1]=true;
        if(a[i]>1 && counted[a[i]-2]){
            count++;
        }
    }
    cout<<n-count;
}