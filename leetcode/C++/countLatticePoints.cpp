#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        bool matrix[201][201];int ans=0;
        for(int i=0;i<201;i++)
        {
            for(int j=0;j<201;j++)
            {
                matrix[i][j]=false;
            }
        }
        for(int i=0;i<circles.size();i++)
        {
            vector<int> circle=circles[i];
            int row=circle[0]-circle[2];
            int col=circle[1]-circle[2];
            for(int j=0;j<=2*circle[2];j++)
            {
                for(int k=0;k<=2*circle[2];k++)
                {
                    if(checkDistance(row+j,col+k,circle[0],circle[1],circle[2])==true)
                    {
                        matrix[row+j][col+k]=true;
                    }
                }
            }
        }
        for(int i=0;i<201;i++)
        {
            for(int j=0;j<201;j++)
            {
                if(matrix[i][j]==true)
                ans++;
            }
        }
        return ans;
    }
    bool checkDistance(int row,int col,int centerRow,int centerCol,int distance)
    {
        int rowdis=row-centerRow;
        int coldis=col-centerCol;
        if(rowdis*rowdis+coldis*coldis<=distance*distance) return true;
        return false;
    }
};