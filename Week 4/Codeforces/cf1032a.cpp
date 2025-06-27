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
        int n,s,min=1000,max=-1;
        cin>>n>>s;
        vector<int> arr(n);
        fori(n){
            cin>>arr[i];
            if(arr[i]>max){max=arr[i];}
            if(arr[i]<min){min=arr[i];}
        }
        if(min>s){
            cout<<max-s<<"\n";
        }
        else if(max<s){
            cout<<s-min<<"\n";
        }else{
            cout<<max-min+(max-s>s-min ? s-min:max-s)<<"\n";
        }
    }
}