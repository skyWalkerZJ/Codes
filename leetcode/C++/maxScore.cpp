#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<int> fushu;int ans=0;
        vector<int> zhengshu;vector<int> zero;
        for(auto i:nums)
        {
            if(i>0) zhengshu.push_back(i);
            else if(i<0) fushu.push_back(i);
            else zero.push_back(i);
        }
        sort(zhengshu.begin(),zhengshu.end());
        sort(fushu.begin(),fushu.end());
        long preSum=0;
        for(auto i:zhengshu)
        {
            preSum+=i;
            if(preSum>0) ans++;
        }
        if(preSum>0) ans+=zero.size();
        for(int i=fushu.size()-1;i>=0;i--)
        {
            preSum+=fushu[i];
            if(preSum>0) ans++;
            else break;
        }
        return ans;
    }
};