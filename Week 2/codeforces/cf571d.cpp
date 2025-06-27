#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    double sum=0;
    cin>>n;
    vector<double>v(n);
    vector<bool>floored(n,false);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(ceil(v[i])!=floor(v[i])){
            floored[i]=true;;
        }
        v[i]=floor(v[i]);
        sum+=v[i];
    }
    for(int i=0;i<n;i++){
        if(floored[i] && sum!=0){
            v[i]++;
            sum+=1;
        }
        cout<<v[i]<<endl;
    }
}