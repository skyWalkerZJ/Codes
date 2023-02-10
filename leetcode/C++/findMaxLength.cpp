#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;int n=nums.size();int sum=0;
        unordered_map<int,int> hashmap;
        hashmap.insert(pair<int,int>{0,-1});
        for(int i=0;i<n;i++)
        {
             if(nums[i]==0) sum--;
             else sum++;
             if(hashmap.find(sum)==hashmap.end()) hashmap.insert(pair<int,int>{sum,i});
             else ans=max(ans,i-hashmap[sum]);
        }
        return ans;
    }
};