#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int start=0,end=nums.size()-1;
        while(start<=end){
            while(abs(nums[start])>abs(nums[end])){
                ans.push_back(abs(nums[start])*abs(nums[start]));
                start++;
            }
            while(abs(nums[start])<abs(nums[end])){
                ans.push_back(abs(nums[end])*abs(nums[end]));
                end--;
            }
            while(abs(nums[start])==abs(nums[end])){
                ans.push_back(abs(nums[start])*abs(nums[start]));
                if(start!=end){
                    ans.push_back(abs(nums[start])*abs(nums[start]));
                }
                start++;
                end--;
                if(start>end){
                    break;
                }
            }
            if(start>=end){
                reverse(ans.begin(),ans.end());
                return ans;
            }
        }
    }
};