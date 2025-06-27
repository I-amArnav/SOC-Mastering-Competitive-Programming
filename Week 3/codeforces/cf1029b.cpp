#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        int index=0;
        for(int i=1;i<=n;i++){
            v[index]=i;
            if(i%4==1){
                index=n-1-index;
            }else if(i%4==2){
                index--;
            }else if(i%4==3){
                index=n-1-index;
            }else{
                index++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
}