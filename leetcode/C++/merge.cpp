#include <algorithm>
#include <vector>
using namespace std;
bool cmp(const vector<int>& a,const vector<int>& b)
{
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),cmp);
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(vector<int> v:intervals)
        {
            if(v[0] >end)
            {
                ans.push_back(vector<int>{start,end});
                start=v[0];
                end=v[1];
            }else{
                end=max(end,v[1]);
            }
        }
        ans.push_back(vector<int>{start,end});
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v{{1,3},{2,6},{8,10},{15,18}};
    s.merge(v);
}