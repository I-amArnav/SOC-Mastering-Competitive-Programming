#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n,m;
int seen[1000][1000];
int arr[1000][1000];
 
void search(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m){
        return;
    }
    if(!arr[x][y]){
        return;
    }
    if(seen[x][y]){
        return;
    }
    seen[x][y]=1;
    search(x-1,y);
    search(x+1,y);
    search(x,y-1);
    search(x,y+1);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    char c;
    int count=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            if(c=='.'){
                arr[i][j]=1;
                seen[i][j]=0;
            }
            else{
                arr[i][j]=0;
                seen[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                continue;
            }
            if(seen[i][j]){
                continue;
            }
            search(i,j);
            count+=1;
        }
    }
    cout<<count;
}
