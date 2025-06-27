#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

//didn't complete.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,extra=0;
    cin>>n;
    string s;
    cin>>s;
    int k=s.size();
    for(int i=0;i<k;i++){
        if(s[i]=='('){
            extra++;
        }else{
            extra--;
        }
    }

}