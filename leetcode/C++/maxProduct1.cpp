#include <vector>
using namespace std;
class Solution {
public:
    //152. 乘积最大子数组
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        int firstPos=1;int firstNeg=1;int preSum=1;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,nums[i]);
            if(nums[i]==0)
            {
                preSum=1;
                firstNeg=1;
            }else{
                preSum*=nums[i];
                if(preSum<0) {
                    ans=max(ans,preSum/firstNeg);
                    if(firstNeg==1) firstNeg=preSum;
                }else{
                    ans=max(ans,preSum/firstPos);
                }
            }
        }
        return ans;
    }
};