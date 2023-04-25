#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> ans(n+1,-1);
        vector<vector<pair<int,int>>> graph(n+1);
        ans[k]=0;
        for(vector<int> v:times)
        {
            graph[v[0]].push_back(pair<int,int>{v[1],v[2]});
        }           

        queue<int> q;
        q.emplace(k);
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            for(pair<int,int> pair:graph[front])
            {
                int temp=ans[pair.first];
                if(temp>=0)
                {
                    ans[pair.first]=min(ans[pair.first],ans[front]+pair.second);
                    if(temp>ans[pair.first]) q.emplace(pair.first);
                }else{
                    ans[pair.first]=ans[front]+pair.second;
                    q.emplace(pair.first);
                }
            }
        }

        int res=-1;
        for(int i=1;i<=n;i++)
        {
            if(ans[i]==-1) return -1;
            res=max(res,ans[i]);
        }
        return res;
    }
};