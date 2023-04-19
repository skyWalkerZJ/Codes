#include <vector>
using namespace std;
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left=1;int right=0;int ans=0;
        for(int n:nums) right=max(right,n);

        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int count=0;int last=-2;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<=mid && i-last>1) {
                    count++;
                    last=i;
                }
            }
            if(count>=k)
            {
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};