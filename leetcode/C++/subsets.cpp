#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int size=0;
        for(int i=0;i<n;i++)
        {
            size |= ( 1<< i );
        }

        for(int i=0;i<=size;i++)
        {
            vector<int> oneAns;
            int num=i;
            for(int i=0;i<n;i++)
            {
                if(num%2==1) oneAns.push_back(nums[i]);
                num = num>>1;
            }
            ans.push_back(oneAns);
        }
        return ans;
    }
};
int main()
{

}