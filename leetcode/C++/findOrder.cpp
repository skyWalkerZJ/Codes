#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visit;
    bool valid=true;
    stack<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visit.resize(numCourses);
        for(vector<int> v:prerequisites)
        {
            edges[v[1]].push_back(v[0]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if(!visit[i]) dfs(i);
            if(!valid) return vector<int>{};
        }

        vector<int> res;
        while(!ans.empty())
        {
            res.push_back(ans.top());
            ans.pop();
        }
        return res;
    }

    void dfs(int root)
    {
        visit[root]=1;
        for(int i:edges[root])
        {
            if(!visit[i])
            {
                dfs(i);
            }else if(visit[i]==1){
                valid=false;
                return;
            }
        }
        visit[root]=2;
        ans.push(root);
    }
};