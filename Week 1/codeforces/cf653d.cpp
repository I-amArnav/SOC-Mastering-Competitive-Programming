#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        ll count=0;
        cin>>n>>k;
        vector<int> a(n);
        int maxfreq=0;
        map <int,int> freq;
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]=k-a[i]%k;
            if(a[i]!=k){
                freq[a[i]]++;
                if(freq[a[i]]>maxfreq){
                    maxfreq=freq[a[i]];
                }
            }
        }
        for(auto [i,f] : freq){
            if(f==maxfreq){
                count=1LL*(f-1)*k+i+1;
            }
        }
        if(count<0){
            count=0;
        }
        cout<<count<<endl;
    }
}