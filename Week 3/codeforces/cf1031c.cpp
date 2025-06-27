#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

//incorrect!!!!!!!!!!!!!!!!!!!!!!!!

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
            }
        }
        while(true){
            int best_gain=-1,best=INT_MIN;
            vector<pair<int, int>> bestdeal;
            fori(n){
                forj(m){
                    int gain=0,benefit=0;
                    vector<pair<int,int>>dealt;
                    int r1 = i - k, r2 = i + k;
                    int c1 = j - k, c2 = j + k;
                    for(int y=c1;y<=c2;y++){
                        if (r1 >= 0 && y >= 0 && r1 < n && y < m && arr[r1][y] == 'g'){
                            dealt.emplace_back(r1, y);
                            gain++;
                        }
                        if (r2 >= 0 && y >= 0 && r2 < n && y < m && arr[r2][y] == 'g'){
                            dealt.emplace_back(r2, y);
                            gain++;
                        }
                    }
                    for (int x=r1+1; x<r2; x++) {
                        if (x >= 0 && x < n) {
                            if (c1 >= 0 && c1 < m && arr[x][c1] == 'g'){
                                dealt.emplace_back(x, c1);
                                gain++;
                            }   
                            if (c2 >= 0 && c2 < m && arr[x][c2] == 'g'){
                                dealt.emplace_back(x, c2);
                                gain++;
                            }    
                        }
                    }
                    benefit=gain;
                    for (int x = r1 + 1; x < r2; ++x) {
                        for (int y = c1 + 1; y < c2; ++y) {
                            if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == 'g'){
                                dealt.emplace_back(x, y);
                                benefit--;
                            }
                        }
                    }
                    if(benefit>best || (benefit==best && gain>best_gain)){
                        best=benefit;
                        best_gain=gain;
                        bestdeal=dealt;
                    }
                }
            }
            if(best<=0){break;}
            for(auto[x,y] : bestdeal){arr[x][y]='i';}
            total+=best_gain;
        }
        cout<<total<<endl;
    }
}