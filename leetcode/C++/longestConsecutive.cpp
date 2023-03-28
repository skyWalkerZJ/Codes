#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;int ans=0;
        for(int num:nums)
        {
            hashset.emplace(num);
        }
        for(auto itr=hashset.begin();itr!=hashset.end();itr++)
        {
            int num=*itr;
            if(hashset.count(num-1)) continue;
            else{
                int size=0;
                while(hashset.count(num))
                {
                    size++;
                    num++;
                }
                ans=max(ans,size);
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v{1,2,3,4};
    s.longestConsecutive(v);
}