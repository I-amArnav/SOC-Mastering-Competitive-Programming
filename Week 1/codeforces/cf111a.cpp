#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0,partialsum=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    for(int i=0;i<n;i++){
        partialsum+=a[i];
        if(partialsum*2>sum){
            cout<<i+1<<endl;
            break;
        }
    }
}