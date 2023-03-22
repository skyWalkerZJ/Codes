#include <vector>
using namespace std;
class Solution {
public:
    bool valid;
    int UNCOLORED=0;
    int RED=1;
    int GREEN=2;
    vector<int> ans;
    bool isBipartite(vector<vector<int>>& graph) {
        valid=true;int n=graph.size();
        ans.assign(n,0);
        for(int i=0;i<n&&valid;i++)
        {
            if(ans[i]==UNCOLORED)
            {
                dfs(i,RED,graph);
            }
        }
        return valid;
    }
    void dfs(int node,int color,vector<vector<int>>& graph)
    {
        if(ans[node]!=UNCOLORED&&ans[node]!=color){
            valid=false;
            return;
        }
        ans[node]=color;
        int ToColor=color==RED?GREEN:RED;
        for(int n:graph[node])
        {
            if(ans[n]==UNCOLORED) 
            {
                dfs(n,ToColor,graph);
            }else if (ans[n]!=ToColor)
            {
                valid=false;
                return;
            }
        }
    }
};