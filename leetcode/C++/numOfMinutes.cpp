#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> map;
        for(int i=0;i<n;i++)
        {
            if(i!=headID)
            {
                map[manager[i]].push_back(i);
            }
        }
        queue<int> q;
        q.emplace(headID);
        manager[headID]=0;
        while(!q.empty())
        {
            int root=q.front();
            q.pop();
            int k=manager[root];
            vector<int>& v=map[root];
            for(int i:v)
            {
                manager[i]=informTime[root]+k;
                q.emplace(i);
            }
        }
        int ans=0;
        for(int i:manager)
        {
            ans=max(ans,i);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v{2,2,-1,2,2,2};
    vector<int> m{0,0,1,0,0,0};
    s.numOfMinutes(6,2,v,m);
}