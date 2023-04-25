#include <vector>
using namespace std;
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,0);
        vector<vector<int>> dis(n+1,vector<int>{});
        for(vector<int> v:dislikes)
        {
            dis[v[0]].push_back(v[1]);
            dis[v[1]].push_back(v[0]);
        }

        for(int i=1;i<=n;i++)
        {
            if(color[i]==0)
            {
                bool res=dfs(i,color,dis);
                if(!res) return false;
            } 
        }
        return true;
    }
    //1:RED 2:BLUE 0:NULL
    bool dfs(int index,vector<int>& color,vector<vector<int>>& dis)
    {
        bool res=true;
        if(color[index]==0) color[index]=1;
        for(int n:dis[index])
        {
            if(color[index]==color[n]) return false;
            if(color[n]==0)
            {
                color[n]=color[index]==1?2:1;
                res &= dfs(n,color,dis);
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v{{1,2},{1,3},{2,4}};
    s.possibleBipartition(4,v);
}