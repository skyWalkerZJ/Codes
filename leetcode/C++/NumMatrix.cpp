#include <vector>
using namespace std;
class NumMatrix {
public:
    vector<vector<int>> ans;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            int sum=0;
            vector<int> curRow=matrix[i];
            vector<int> row;
            row.push_back(0);
            for(int j=0;j<m;j++)
            {
                sum+=curRow[j];
                row.push_back(sum);
            }
            ans.push_back(row);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++)
        {
            sum+=(ans[i][col2+1]-ans[i][col1]);
        }
        return sum;
    }
};