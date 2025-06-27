#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,a,b;
    cin>>n;
    vector<tuple<int,int,int>>people(n);
    for(int i=0;i<n;i++){
        cin>>a>>b;
        people[i]={a,b,i};
    }
    sort(people.begin(),people.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    vector<int>alloted(n);
    int count=0;
    for(auto [a,d,i]:people){
        int room;
        if(!pq.empty() && pq.top().first<a){
            room=pq.top().second;
            pq.pop();
        }else{
            count+=1;
            room=count;
        }
        pq.emplace(d,room);
        alloted[i]=room;
    }
    cout<<count<<"\n";
    for(int i=0;i<n;i++){
        cout<<alloted[i]<<" ";
    }
}