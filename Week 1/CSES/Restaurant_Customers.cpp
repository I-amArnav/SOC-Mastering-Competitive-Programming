#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,best=0,count=0;
    cin>>n;
    map<int,int> arrive,depart;
    vector<int> t(2*n);
    for(int i=0;i<2*n;i+=2){
        cin>>t[i];
        arrive[t[i]]=1;
        cin>>t[i+1];
        depart[t[i+1]]=1;
    }
    sort(t.begin(),t.end());
    for(int i=0;i<2*n;i++){
        if(arrive[t[i]]){
            count+=1;
        }
        if(depart[t[i]]){
            count-=1;
        }
        if(count>best){
            best=count;
        }
    }
    cout<<best;
}