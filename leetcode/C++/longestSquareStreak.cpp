#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        unordered_map<long,int> hashmap;
        for(int i=0;i<nums.size();i++)
        {
            if(hashmap.find(nums[i])!=hashmap.end())
            {
                int cnt=hashmap.find(nums[i])->second;
                hashmap.insert(pair<long,int>((long)nums[i]*nums[i],cnt+1));
            }else{
                hashmap.insert(pair<long,int>((long)nums[i]*nums[i],1));
            }
        }
        for(auto itr=hashmap.begin();itr!=hashmap.end();itr++)
        {
            ans=max(ans,itr->second);
        }
        return ans==1?-1:ans;
    }
};