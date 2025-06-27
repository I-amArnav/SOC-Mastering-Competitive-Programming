#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,sum=0;
        cin>>n>>k;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        reverse(b,b+n);
        for(int i=0;i<n;i++){
            if(i<k){
                sum+=(a[i]>b[i] ? a[i]:b[i]);
            }
            else{
                sum+=a[i];
            }
        }
        cout<<sum<<endl;
    }
}