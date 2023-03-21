#include <vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans(target+1,0);
        ans[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums[j]<=i && ans[i-nums[j]] <__INT_MAX__-ans[i]) ans[i]+=ans[i-nums[j]];
            }
        }
        return ans[target];
    }
};