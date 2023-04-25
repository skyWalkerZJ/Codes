#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            int node1=edges[i][0];
            int node2=edges[i][1];
            if(find(parent,node1)==find(parent,node2))
            {
                return edges[i];
            }else{
                Union(parent,node1,node2);
            }
        }
        return vector<int>{};
    }
    int find(vector<int>& parent,int target)
    {
        while(parent[target]!=target)
        {
            target=parent[target];
        }
        return target;
    }

    void Union(vector<int>&parent,int target1,int target2)
    {
        int root1=find(parent,target1);
        int root2=find(parent,target2);
        parent[root1]=root2;
        return;
    }
};