#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct range{
    int x,y,index;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,miny=0,maxy=0;
    cin>>n;
    vector<bool>contains(n,false),iscontained(n,false);
    vector<range>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].x>>vec[i].y;
        vec[i].index=i;
    }
    sort(vec.begin(), vec.end(), [](const range &a, const range &b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
    });

    for(int i=n-1;i>=0;i--){
        if(i==n-1){miny=vec[i].y;continue;}
        if(vec[i].y>=miny){
            contains[vec[i].index]=true;
        }
        else{
            miny=vec[i].y;
        }
    }
    for(int i=0;i<n;i++){
        if(vec[i].y<=maxy){
            iscontained[vec[i].index]=true;
        }
        else{
            maxy=vec[i].y;
        }
    }
    for(int i=0;i<n;i++){
        cout<<contains[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<iscontained[i]<<" ";
    }
}