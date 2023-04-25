#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            bool res=dfs(graph,i,color);
            if(res) ans.push_back(i);
        }
        return ans;
    }

    bool dfs(vector<vector<int>>& graph,int index,vector<int>& color)
    {
        if(color[index]>0)
        {
            return color[index]==2;
        }
        color[index]=1;

        for(int y:graph[index])
        {
            if(!dfs(graph,y,color))
            {
                return false;
            }
        }
        color[index]=2;
        return true;
    }
};