#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;int right=nums.size()-1;
        int ans=nums.size();
        while(left<=right)
        {
            int mid=((right-left)>>1)+left;
            if(nums[mid]>=target) {
                right=mid-1;
                ans=mid;
            }
            else left=mid+1;
        }
        return ans;
    }
};