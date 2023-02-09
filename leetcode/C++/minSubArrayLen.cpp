#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target,vector<int> nums)
    {
        int left=0;int right=0;int ans=__INT_MAX__;
        int n=nums.size();int sum=0;
        while(right<n)
        {
            if(sum>=target)
            {
                ans=min(ans,right-left);
            }
            if(sum<target) {
                sum+=nums[right];
                right++;
            }
            else{
                sum-=nums[left];
                left++;
            }
        }
        
        while(sum>=target)
        {
            ans=min(ans,right-left);
            sum-=nums[left];
            left++;
        }
        return ans==__INT_MAX__?0:ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums={1,1,1,1,1,1,1,1,3,5,2};
    cout<<s.minSubArrayLen(11,nums);
}
