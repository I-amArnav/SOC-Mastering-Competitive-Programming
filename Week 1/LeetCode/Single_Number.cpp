#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        for (auto& [key, value] : m) {
            if (value == 1) {
                return key;
            }
        }
        return 0;
    }
};