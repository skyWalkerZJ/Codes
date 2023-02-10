#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();int sum=0;int ans=0;
        unordered_map<int,int> hashmap;
        hashmap.insert(pair<int,int>{0,1});
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans+=hashmap[sum-k];
            hashmap[sum]++;
        }
        return ans;
    }
};