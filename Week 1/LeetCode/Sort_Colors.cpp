#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColorsOld(vector<int>& nums) {
        auto start = nums.begin(),end = nums.end()-1,it=nums.begin();
        while(it<=end){
            if(*it==0){
                if(it<=start){
                    it++;
                    continue;
                }
                swap(*start,*it);
                start++;
                if(*it==1){
                    it++;
                }
            }
            else if(*it==2){
                swap(*end,*it);
                end--;
                if(*it==1){
                    it++;
                }
            }
            else{
                it++;
            }
        }
        for(int num:nums){
            cout<<num<<" ";
        }
    }

    void sortColors(vector<int>& nums) {
        int start=0,end=nums.size()-1,temp=0;
        while(temp<=end){
            if(nums[temp]==0){
                swap(nums[temp],nums[start]);
                start++;
                temp++;
            }
            else if(nums[temp]==1){
                temp++;
            }
            else{
                swap(nums[temp],nums[end]);
                end--;
            }
        }
    }
};
