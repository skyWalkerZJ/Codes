#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<long long> visit;
    vector<vector<pair<int,int>>> edges;
    long long minAns=LONG_LONG_MAX;
    int ans=0;
    int countPaths(int n, vector<vector<int>>& roads) {
        edges.resize(n);
        visit.assign(n,LONG_LONG_MAX);
        for(vector<int> v:roads)
        {
            edges[v[0]].push_back(pair<int,int>{v[1],v[2]});
            edges[v[1]].push_back(pair<int,int>{v[0],v[2]});
        }
        dfs(0,0,n);
        minAns=visit[n-1];
        dfs1(0,0,n);
        return ans;
    }

    void dfs(int root,long long time,int n)
    {
        if(root==n-1) {
            if(time<visit[root])
            {
                visit[root]=time;
            }
            return;
        }
        if(time<visit[root]) 
        {
            visit[root]=time;
            for(pair<int,int> p:edges[root])
            {
                dfs(p.first,time+p.second,n);
            }
        }else{
            return;
        }
    }

    void dfs1(int root,long long time,int n)
    {
        if(time>minAns) return;
        if(root==n-1&&time==minAns) {
            ans++;
            ans=(ans%(int)(1e9+7));
            return;
        }
        if(time<=visit[root]) 
        {
            for(pair<int,int> p:edges[root])
            {
                dfs1(p.first,time+p.second,n);
            }
        }else{
            return;
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v{{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    s.countPaths(7,v);
}