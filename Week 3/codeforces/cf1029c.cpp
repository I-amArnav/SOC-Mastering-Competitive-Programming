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
        int n,count=1;
        map<int,int>freq;
        bool quit=false;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            freq[v[i]]++;
        }
        int i=0,start=0;
        while(i<n){
            start=v[i];
            if(freq[v[i]]==1){
                count++;
                break;
            }
            freq[start]--;
            i++;
            while(v[i]!=start){
                freq[v[i]]--;
                if(freq[v[i]]==1){
                    quit=true;
                    break;
                }
                i+=1;
            }
            count++;
            i+=1;
            if(quit){break;}
        }
        cout<<count<<"\n";
    }
}
//incomplete