#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates,0,target,ans,combine);
        return ans;
    }
    void dfs(vector<int>& candidates,int cur,int target,vector<vector<int>>& ans,vector<int>& combine)
    {
        if(cur==candidates.size()) return;
        if(target==0) {ans.push_back(combine);return;}
        dfs(candidates,cur+1,target,ans,combine);

        if(target-candidates[cur]>=0)
        {
            combine.push_back(candidates[cur]);
            dfs(candidates,cur,target-candidates[cur],ans,combine);
            combine.pop_back();
        }
    }
};