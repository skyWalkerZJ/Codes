#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        int vectorSize=0;
        for(int num:nums)
        {
            hashmap[num]++;
            vectorSize=max(vectorSize,hashmap[num]);
        }
        vector<vector<int>> ans(vectorSize);
        for(auto itr=hashmap.begin();itr!=hashmap.end();itr++)
        {
            int num=(*itr).first;
            int size=(*itr).second;
            for(int i=0;i<size;i++)
            {
                ans[i].push_back(num);
            }
        }
        return ans;
    }
};