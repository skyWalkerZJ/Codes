#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> hashmap={{0,1}};
        int sum=0;int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int temp=sum-goal;
            if(hashmap.count(temp))
            {
                ans+=hashmap[temp];
            }
            hashmap[sum]++;
        }
        return ans;
    }
};