#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();int m=mat[0].size();
        ans.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!mat[i][j]) continue;

            }
        }
    }

    int dfs(vector<vector<int>>& mat,int i,int j)
    {
        if(mat[i][j]==0){
            ans[i][j]=0;
            return 0;
        }
        
    }   
};