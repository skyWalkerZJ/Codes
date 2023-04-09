#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m=grid.size();int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        ans[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int t=grid[i][j];
                if(t==0 || grid[i][j]==INT_MAX) continue;
                for(int k=1;k<=t;k++)
                {
                    if(i+k>=m && j+k>=n) break;
                    if(i+k<m) ans[i+k][j]=min(ans[i+k][j],ans[i][j]+1);
                    if(j+k<n) ans[i][j+k]=min(ans[i][j+k],ans[i][j]+1);
                }
            }
        }
        if(ans[m-1][n-1]==INT_MAX) return -1;
        else return ans[m-1][n-1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{3,4,2,1},{4,2,1,1},{2,1,1,0},{3,4,1,0}};
    cout<<s.minimumVisitedCells(v);
}