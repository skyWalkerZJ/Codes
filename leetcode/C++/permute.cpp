#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums,0,ans);
        return ans;
    }

    void backtrack(vector<int>& nums,int first,vector<vector<int>> ans)
    {
        if(first==nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i=first;i<nums.size();i++)
        {
            swap(nums[first],nums[i]);
            backtrack(nums,first+1,ans);
            swap(nums[first],nums[i]);
        }
    }
};