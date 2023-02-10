#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();int ans=-1;int sum=0;
        vector<int> preindex;
        preindex.push_back(0);
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            preindex.push_back(sum);
        }
        for(int i=0;i<n;i++)
        {
            sum-=nums[i];
            if(sum==preindex[i]) {ans=i;break;}
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums={1,7,3,6,5,6};
    s.pivotIndex(nums);
}