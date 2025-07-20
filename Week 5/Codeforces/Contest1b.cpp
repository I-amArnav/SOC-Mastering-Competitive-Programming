#include<bits/stdc++.h>
using namespace std;
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
typedef long long ll;
const ll mod=1e9+7;

int main(){
    string s;cin>>s;
    int n=s.size();
    vector<bool>used(n,false);
    vector<vector<int>>o;
    while(true){
        vector<int> left,right;
        fori(n){
            if(!used[i] && s[i]=='('){
                left.push_back(i);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(!used[i] && s[i]==')'){
                right.push_back(i);
            }
        }
        vector<int>indices;
        int i=0,j=0;
        while(i<left.size() && j<right.size()){
            if(left[i]<right[j]){
                indices.push_back(left[i]);
                indices.push_back(right[j]);
                ++i;
                ++j;
            }else{
                j++;
            }
        }
        if(indices.empty()){break;}
        sort(indices.begin(),indices.end());
        for(auto e:indices){
            used[e]=true;
        }
        o.push_back(indices);
    }
    cout<<o.size()<<endl;
    for(auto v:o){
        cout<<v.size()<<endl;
        for(int e:v){
            cout<<e+1<<" ";
        }
        cout<<endl;
    }
}