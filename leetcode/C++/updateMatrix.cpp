#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();int n=mat[0].size();
        queue<pair<int,int>> q;vector<vector<int>> pos={{0,-1},{0,1},{1,0},{-1,0}};
        vector<vector<bool>> flags(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.emplace(i,j);
                    flags[i][j]=true;
                }
            }
        }

        while(!q.empty())
        {
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int row=i+pos[k][0];
                int col=j+pos[k][1];
                if(row>=0 && row<m && col>=0 && col<n && !flags[row][col])
                {
                    mat[row][col]=mat[i][j]+1;
                    q.emplace(row,col);
                    flags[row][col]=true;
                }
            }
        }
        return mat;
    }
};