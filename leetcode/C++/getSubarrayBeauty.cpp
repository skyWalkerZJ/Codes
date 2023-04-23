#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans;
        vector<int> negNums(50,0);
        int pos=0;int neg=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0) {
                neg++;
                negNums[nums[i]+50]++;
            }
            else pos++;

            if((neg+pos)>k)
            {
               if(nums[i-k]<0) {
                    neg--;
                    negNums[nums[i-k]+50]--;   
                }
                else pos--;
            }
            if((neg+pos)==k)
            {
                if(neg<x) ans.push_back(0);
                else 
                {
                    ans.push_back(find(negNums,x)); 
                }
            }
        }
        return ans;
    }

    int find(vector<int>& negSums,int x)
    {
        int sum=0;
        for(int i=0;i<50;i++)
        {
            sum+=negSums[i];
            if(sum>=x) return i-50;
        }
        return 0;
    }
};
int main()
{
    vector<int> v{1,-1,-3,-2,3};
    Solution s;
    s.getSubarrayBeauty(v,3,2);
}