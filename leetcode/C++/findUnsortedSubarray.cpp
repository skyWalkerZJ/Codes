#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans=-1;int n=nums.size();
        int maxValue=INT_MIN;int left=INT_MAX;int mid=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=maxValue)
            {
                maxValue=nums[i];
                continue;
            }else{
                if(mid==-1) mid=i;
                int t=upper_bound(nums.begin(),nums.begin()+i,nums[i])-nums.begin();
                left=min(left,t);
            }
        }
        if(left==INT_MAX) return 0;
        mid=-1;
        int minValue=nums[n-1];int right=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<=minValue)
            {
                minValue=nums[i];
                continue;
            }else{
                if(mid==-1) mid=i;
                int t=lower_bound(nums.begin()+i,nums.end(),nums[i])-nums.begin();
                right=max(right,t);
            }
        }
        return right-left;
    }
};