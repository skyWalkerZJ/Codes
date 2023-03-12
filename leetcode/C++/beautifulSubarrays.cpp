#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        int preSum=0;long long ans=0;
        hashmap.emplace(0,1);
        for(auto i:nums)
        {
            preSum^=i;
            ans+=hashmap[preSum];
            hashmap[preSum]++;
        }
        return ans;
    }
};