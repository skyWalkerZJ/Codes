#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        hashmap.emplace(0,1);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> map;
            for(auto iter=hashmap.begin();iter!=hashmap.end();iter++)
            {
                map[(*iter).first+nums[i]]+=(*iter).second;
                map[(*iter).first-nums[i]]+=(*iter).second;
            }
            hashmap=map;
        }
        return hashmap[target];
    }
    
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return count;
    }
    void backtrack(vector<int>& nums, int target, int index, int sum) {
        if (index == nums.size()) {
            if (sum == target) {
                count++;
            }
        } else {
            backtrack(nums, target, index + 1, sum + nums[index]);
            backtrack(nums, target, index + 1, sum - nums[index]);
        }
    }
};