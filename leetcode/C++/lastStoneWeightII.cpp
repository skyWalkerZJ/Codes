#include <vector>
using namespace std;
class Solution {
public:
    int ans=__INT_MAX__;
    int lastStoneWeightII(vector<int>& stones) {
        dfs(stones,0,0);
        return ans;
    }

    //回溯 会超时
    void dfs(vector<int>& stones,int cur,int sum)
    {
        if(cur==stones.size()) {
            ans=min(sum,ans);
            return;
        }
        dfs(stones,cur+1,sum-stones[cur]);
        dfs(stones,cur+1,sum+stones[cur]);
    }

    //0-1背包问题
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(auto n:stones)
        {
            sum+=n;
        }
        int neg=sum/2;
        vector<vector<bool>> ans(n+1,vector<bool>(neg+1,false));
        ans[0][0]=true;
        for (int i = 1; i <= n; i++)
        {
            int stone=stones[i-1];
            for(int j=0;j<=neg;j++)
            {
                ans[i][j]=ans[i-1][j];
                if(stone<=j) ans[i][j] = ans[i][j] | ans[i-1][j-stone];
            }
        }
        for(int j=neg;j>=0;j--)
        {
            if(ans[n][j]) return sum-2*j;
        }
        return 0;
    }
};