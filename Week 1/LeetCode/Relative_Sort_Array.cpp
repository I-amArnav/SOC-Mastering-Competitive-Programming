#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> freq;
        map<int,int> m;
        vector<int> ans;
        for(int num : arr1){
            freq[num]+=1;
        }
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<freq[arr2[i]];j++){
                ans.push_back(arr2[i]);
            }
            m[arr2[i]]=1;
        }
        sort(arr1.begin(),arr1.end());
        for(int i=0;i<arr1.size();i++){
            if(m[arr1[i]]){
                continue;
            }
            ans.push_back(arr1[i]);
        }
        return ans;
    }
};