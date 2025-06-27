#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,count=0,best=-1;
        cin>>n;
        int a;
        map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>a;
            if(m.count(a)){
                if(best>i-m[a]+1 || best==-1){
                    best=i-m[a]+1;
                }
            }
            m[a]=i;
        }
        cout<<best<<endl;
    }
}