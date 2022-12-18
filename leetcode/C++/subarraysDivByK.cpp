#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;int ans=0;
        unordered_map<int,int> hashmap={{0,1}};
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int t=(sum%k+k)%k;
            if(hashmap.count(t))
            {
                ans+=hashmap[t];   
            }
            hashmap[t]++;
        }
        return ans;
    }
};