#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    vector<int>freq(3,0);
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            freq[0]++;
        }
        if(s[i]=='1'){
            freq[1]++;
        }
        if(s[i]=='2'){
            freq[2]++;
        }
    }
    int delta0=freq[0]-n/3;
    int delta2=freq[2]-n/3;
    int delta1=freq[1]-n/3;
    if(delta0<0){
        for(int i=0;i<n;i++){
            if(s[i]=='1' && delta1>0){
                s[i]='0';
                delta0+=1;
                delta1-=1;
            }
            if(s[i]=='2' && delta2>0){
                s[i]='0';
                delta0+=1;
                delta2-=1;
            }
            if(delta0==0){
                break;
            }
        }
    }
    if(delta2<0){
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1' && delta1>0){
                s[i]='2';
                delta2+=1;
                delta1-=1;
            }
            if(s[i]=='0' && delta0>0){
                s[i]='2';
                delta2+=1;
                delta0-=1;
            }
            if(delta2==0){
                break;
            }
        }
    }
    if(delta2>0){
        for(int i=0;i<n;i++){
            if(s[i]=='2'){
                s[i]='1';
                delta1++;
                delta2--;
            }
            if(delta2==0){
                break;
            }
        }
    }
    if(delta0>0){
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                s[i]='1';
                delta1++;
                delta0--;
            }
            if(delta0==0){
                break;
            }
        }
    }
    cout<<s;
}