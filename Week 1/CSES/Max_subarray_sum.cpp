#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long a[n];
    cin>>a[0];
    long long max=a[0],sum=a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        sum=(sum>0 ? a[i]+sum:a[i]);
        if(sum>max){
            max=sum;
        }
    }
    cout<<max;
}