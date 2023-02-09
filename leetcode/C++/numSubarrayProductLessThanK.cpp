#include <vector>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0;int right=0;int sum=1;
        int ans=0;int n=nums.size();
        if(k==0) return 0;
        while(right<n)
        {
            sum*=nums[right];
            while(left<=right&&sum>=k)
            {
                sum/=nums[left];
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
    }
};