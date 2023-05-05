#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row0=1;
        int colo=1;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==0) {row0=0;break;}
        }
        for(int i=0;i<m;i++)
        {
            if(matrix[0][i]==0) {colo=0;break;}
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=1;j<m;j++) 
                matrix[i][j]=0;
            }
        }
        for(int i=1;i<m;i++)
        {
            if(matrix[0][i]==0){
                for(int j=1;j<n;j++) matrix[j][i]=0;
            }
        }

        if(row0==0)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0]=row0;
            }
        }
        if(colo==0)
        {
            for(int i=0;i<m;i++)
            {
                matrix[0][i]=colo;
            }
        }
        return;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v{{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(v);
}