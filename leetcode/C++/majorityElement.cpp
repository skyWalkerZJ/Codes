#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //摩尔投票法
    vector<int> majorityElement(vector<int>& nums) {
        int element1=0;int element2=0;
        int vote1=0,vote2=0;
        vector<int> ans;
        for(auto &num:nums)
        {
            if(vote1>0&&num==element1) vote1++;
            else if(vote2>0&&num==element2) vote2++;
            else if(vote1==0) {element1=num;vote1++;}
            else if(vote2==0) {element2=num;vote2++;}
            else{
                vote1--;
                vote2--;
            }
        }
        int size1=0,size2=0;
        for(int &num:nums)
        {
            if(vote1>0&&num==element1)
            size1++;
            else if(vote2>0&&num==element2)
            size2++;
        }
        if(vote1>0&&size1>nums.size()/3) ans.push_back(element1);
        if(vote2>0&&size2>nums.size()/3) ans.push_back(element2);
        return ans;
    }
};
