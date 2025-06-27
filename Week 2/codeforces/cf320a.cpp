#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x,count=0;
    cin>>x;
    while(x>0){
        if(x%2){
            count+=1;
        }
        x/=2;
    }
    cout<<count<<"\n";
}