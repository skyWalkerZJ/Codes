#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> edges; 
    vector<int> visit;
    bool valid=true;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visit.assign(numCourses,0);
        for(vector<int> v:prerequisites)
        {
            edges[v[1]].push_back(v[0]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if(!visit[i])
                dfs(i);
        }
        return valid;
    }

    void dfs(int root)
    {
        visit[root]=1;
        for(int i:edges[root])
        {
            if(!visit[i]) dfs(i);
            if(visit[i]==1) {
                valid=false;
                return;
            }
        }
        visit[root]=2;
    }
};