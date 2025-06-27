#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a*d==b*c){
        cout<<"0/1";
        return 0;
    }
    if(a*d>b*c){
        int num=d*a-b*c;
        int den=d*a;
        int g=gcd(num,den);
        num/=g;
        den/=g;
        cout<<num<<"/"<<den;
    }
    else{
        int num=b*c-d*a;
        int den=b*c;
        int g=gcd(num,den);
        num/=g;
        den/=g;
        cout<<num<<"/"<<den;
    }
}