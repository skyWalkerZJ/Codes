#include <vector>
using namespace std;
class Solution {
public:
    int preSum=0;
    bool canPartition1(vector<int>& nums) {
        int sum=0;
        for(auto n:nums)
        {
            sum+=n;
        }
        if(sum%2==1) return false;
        return dfs(nums,sum/2,0);
    }
    //回溯 会超时
    bool dfs(vector<int>& nums,int target,int cur)
    {
        if(preSum>target||cur==nums.size()) return false;
        if(preSum==target) return true;
        preSum+=nums[cur];
        bool ans=false;
        ans |= dfs(nums,target,cur+1);
        if(ans) return ans;
        preSum-=nums[cur];
        ans |= dfs(nums,target,cur+1);
        return ans;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;int n=nums.size();
        for(auto i:nums)
        {
            sum+=i;
        }
        if(sum%2==1) return false;
        vector<vector<bool>> ans(n+1,vector<bool>(sum/2+1,false));
        ans[0][0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum/2;j++)
            {
                ans[i][j] = ans[i-1][j];
                if(j>=nums[i-1]) 
                {
                    ans[i][j] = ans[i-1][j-nums[i-1]] | ans[i][j];
                }
            }
        }
        return ans[n][sum/2];
    }
};

int main()
{
    Solution s;
    vector<int> v{1,5,5,11};
    s.canPartition(v);
}