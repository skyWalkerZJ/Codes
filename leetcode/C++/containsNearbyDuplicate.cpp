#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(hashmap.count(nums[i])!=0){
                if(i-hashmap[nums[i]]<=k) return true;
            }
            hashmap[nums[i]]=i;
        }
        return false;
    }
};