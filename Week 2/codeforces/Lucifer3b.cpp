#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,money=0;
    cin>>n>>k;
    int a[n],b[n],d[n];
    vector<pair<int,int>> m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        d[i]=b[i]-a[i];
        m.push_back({d[i],i});
    }
    sort(m.begin(),m.end());
    reverse(m.begin(),m.end());
    int count=0;
    for(auto pair : m){
        int i=pair.second;
        if(count<k){
            money+=a[i];
        }
        else if(pair.first>0){
            money+=a[i];
        }
        else{
            money+=b[i];
        }
        count++;
    }
    cout<<money;
}