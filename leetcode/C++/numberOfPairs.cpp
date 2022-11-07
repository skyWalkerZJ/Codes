#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> map;
        for(int x:nums)
        {
            map[x]++;
        }
        int pair=0;
        for(auto iter=map.begin();iter!=map.end();++iter)
        {
            pair+=(iter->second/2);
        }
        ans.push_back(pair);
        ans.push_back(nums.size()-pair*2);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v={3,3,3,3,3};
    s.numberOfPairs(v);
    return 0;
}