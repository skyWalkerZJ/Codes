#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    //超时
    vector<long long> minOperations1(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        for(int i=0;i<queries.size();i++)
        {
            long long res=0;
            for(int j=0;j<nums.size();j++)
            {
                res+=(long long)abs(nums[j]-queries[i]);
            }
            ans.push_back(res);
        }
        return ans;
    }

    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        sort(nums.begin(),nums.end());
        vector<long long> prefix;
        long long pre=0;
        for(int n:nums)
        {
            pre+=(long long)n;
            prefix.push_back(pre);
        }
        int n=queries.size();int m=nums.size();
        for(int i=0;i<n;i++)
        {
            long long target=(long long)queries[i];
            int leftPos=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            int rightPos=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
            int rightSize=m-rightPos;
            long long res=0;
            if(leftPos>0)
            {
                res+=(long long)((long long)(leftPos*target)-(long long)prefix[leftPos-1]);
            }
            if(rightPos<m)
            {
                if(rightPos>0) res+=(long long)(prefix[m-1]-prefix[rightPos-1]-(long long)rightSize*target);
                else res+=(long long)(prefix[m-1]-(long long)rightSize*target);
            }
            ans.push_back(res);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,1,1,1,2,2,3};
    vector<int> q{0,2,5};
    vector<long long> ans=s.minOperations(v,q);
    for(long long l:ans)
    {
        cout<<l<<" ";
    }
}