#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> hashmap;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(hashmap.count(nums[i])==0)
            {
                hashmap.emplace(nums[i],vector<int>{i});
            }else{
                hashmap[nums[i]].push_back(i);
            }
        }
        vector<long long> ans(n,0);

        for(auto iter=hashmap.begin();iter!=hashmap.end();iter++)
        {
            vector<int> temp=(*iter).second;
            int size=temp.size();
            vector<long long> preSum(size,0);
            vector<long long> endSum(size,0);
            long long sum=0;
            for(int i=0;i<size;i++)
            {
                preSum[i]=sum;
                sum+=(long long)temp[i];
            }

            for(int i=0;i<size;i++)
            {
                sum-=temp[i];
                endSum[i]=sum;
            }
            
            for(int i=0;i<size;i++)
            {
                int pos=temp[i];
                long long pre=preSum[i]-(long long)i*pos;
                long long end=endSum[i]-(long long)(size-i-1)*pos;
                ans[pos]=end-pre;
            }
        }
        return ans;
    }
};