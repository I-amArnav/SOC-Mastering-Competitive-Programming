#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,temp;
        bool valid=true;
        cin>>n;
        vector<int>v;
        for(int i=0;i<4*n;i++){
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<2*n;i+=2){
            if((v[i])*(v[4*n-i-1])!=(v[0])*(v[4*n-1]) || v[i]!=v[i+1] || v[4*n-i-1]!=v[4*n-i-2]){
                valid=false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(valid){
            cout<<"YES"<<endl;
        }
    }
}