#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0,best=0;
        unordered_set vowels = {'a','e','i','o','u'};
        for(int i=0;i<k;i++){
            if(vowels.find(s[i])!=vowels.end()){
                count+=1;
            }
        }
        best=count;
        for(int i=k;i<s.size();i++){
            if(vowels.find(s[i-k])!=vowels.end()){
                count-=1;
            }
            if(vowels.find(s[i])!=vowels.end()){
                count+=1;
            }
            if(count>best){
                best = count;
            }
        }
        return best;
    }
};