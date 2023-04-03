#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int pos=abs(nums[i]);
            nums[pos-1]=-abs(nums[pos-1]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) ans.push_back(i+1);
        }
        return ans;
    }
};