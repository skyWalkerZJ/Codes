#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
    
        vector<vector<int>> ans(n,vector<int>(m));
        int sum=0;
        for(int i=0;i<n;i++)
        {  
            sum+=grid[i][0];
            ans[i][0]=sum; 
        }
        sum=0;
        for(int i=0;i<m;i++)
        {
            sum+=grid[0][i];
            ans[0][i]=sum;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                ans[i][j]=grid[i][j]+min(ans[i-1][j],ans[i][j-1]);
            }
        }
        return ans[n-1][m-1];
        //return minPath(grid,n,m,0,0);
    }

    //递归超时
    int minPath(vector<vector<int>>& grid,int n,int m,int col,int row)
    {
        int ans=grid[row][col];
        int minAns=__INT_MAX__;
        if(row+1<n) minAns=min(minAns,minPath(grid,n,m,col,row+1));
        if(col+1<m) minAns=min(minAns,minPath(grid,n,m,col+1,row));
        if(minAns==__INT_MAX__) minAns=0;
        return ans+minAns;
    }
};