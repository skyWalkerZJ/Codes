#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS1(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> preSum;
        for(int i=0;i<n;i++)
        {
            int curAns=0;
            int m=preSum.size();
            for(int j=0;j<m;j++)
            {
                if(nums[j]<nums[i] && preSum[j] >curAns) curAns=preSum[j];
            }
            ans=max(ans,curAns+1);
            preSum.push_back(curAns+1);
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp;
        int len=1;
        dp.push_back(nums[0]);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>dp[len-1])
            {
                dp.push_back(nums[i]);
                len++;
            }else{
                int pos=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[pos]=nums[i];
            }
        }
        return len;
    }
};
int main()
{
    vector<int> v{10,9,2,5,3,7,101,18};
    Solution s;
    s.lengthOfLIS(v);
}