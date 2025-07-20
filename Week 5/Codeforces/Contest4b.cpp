#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;cin>>s;
        int sz=s.size();
        vector<int>digits(sz);
        fori(sz){
            digits[i]=s[i]-'0';
        }
        int n=digits.size();
        bool dualdigited=false;
        int d2=0,d1=0;
        fori(n-1){
            int sum=digits[i]+digits[i+1];
            if(sum>9){
                dualdigited=true;
                d2=i;
            }
        }
        if(dualdigited){
            fori(n){
                if(i==d2){
                    cout<<digits[i]+digits[i+1];
                    i+=1;
                    continue;
                }
                cout<<digits[i];
            }
        }else{
            int i=0;
            while(digits[i+1]==0 && digits[i]==0 && i<n-1){
                i++;
            }
            forj(n){
                if(j==i){
                    cout<<digits[j]+digits[j+1];
                    j++;
                    continue;
                }
                cout<<digits[j];
            }
        }
        cout<<'\n';
    }
}