#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,total=0;
        cin>>n>>m>>k;
        char arr[n][m];
        fori(n){
            forj(m){
                cin>>arr[i][j];
                if(arr[i][j]=='g'){total++;}
            }
        }
        int bestloss=INT_MAX;
        fori(n){
            forj(m){
                if(arr[i][j]!='.'){continue;}
                int gain=0,benefit=0,loss=0;
                int r1 = i - k, r2 = i + k;
                int c1 = j - k, c2 = j + k;
                for(int y=c1;y<=c2;y++){
                    if (r1 >= 0 && y >= 0 && r1 < n && y < m && arr[r1][y] == 'g'){
                        gain++;
                    }
                    if (r2 >= 0 && y >= 0 && r2 < n && y < m && arr[r2][y] == 'g'){
                        gain++;
                    }
                }
                for (int x=r1+1; x<r2; x++) {
                    if (x >= 0 && x < n) {
                        if (c1 >= 0 && c1 < m && arr[x][c1] == 'g'){
                            gain++;
                        }   
                        if (c2 >= 0 && c2 < m && arr[x][c2] == 'g'){
                            gain++;
                        }    
                    }
                }
                benefit=gain;
                for (int x = r1 + 1; x < r2; ++x) {
                    for (int y = c1 + 1; y < c2; ++y) {
                        if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == 'g'){
                            benefit--;
                        }
                    }
                }
                loss=gain-benefit;
                if(loss<bestloss){
                    bestloss=loss;
                }
            }
        }
        total-=bestloss;
        cout<<total<<endl;
    }
}