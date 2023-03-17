#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> combine;
        vector<vector<int>> ans;
        dfs(candidates,combine,ans,target,0);
        return ans;
    }
    void dfs(vector<int>& candidates,vector<int>& combine,vector<vector<int>>& ans,int target,int cur)
    {
        if(target==0){
            ans.push_back(combine);
            return;
        }
        if(cur==candidates.size()) return;
        for(int i=cur;i<candidates.size();i++)
        {
            if(candidates[i]>target) break;
            if(i>cur && candidates[i]==candidates[i-1])
            {
                continue;
            }
            combine.push_back(candidates[i]);
            dfs(candidates,combine,ans,target-candidates[i],i+1);
            combine.pop_back();
        }
    }
};