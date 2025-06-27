#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    bool equal=false;
    cin>>t;
    while(t--){
        int temp[4],min,index=0;
        for(int i=0;i<4;i++){
            if(i==0){
                cin>>min;
                temp[0]=min;
                continue;
            }
            cin>>temp[i];
            if(min>temp[i]){
                min=temp[i];
            }
            if(i>1 && temp[i]==min){
                equal=true;
            }
        }
        if(equal){
            cout<<"Gellyfish"<<"\n";
        }else if(temp[2]==min || temp[3]==min){
            cout<<"Gellyfish"<<"\n";
        }else{
            cout<<"Flower"<<"\n";
        }
    }
}
//incomplete