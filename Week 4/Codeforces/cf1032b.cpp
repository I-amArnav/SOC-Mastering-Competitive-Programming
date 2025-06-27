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
        vector<char> s(n);
        map<char,int>freq;
        bool valid=false;
        fori(n){
            cin>>s[i];
            if(i==n-1){
                if(s[n-1]==s[0]){
                    continue;
                }
            }
            freq[s[i]]++;
            if(freq[s[i]]==2){valid=true;}
        }
        if(valid){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }
}