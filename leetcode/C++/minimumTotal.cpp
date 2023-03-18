#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int i=1;i<n;i++)
        {
            vector<int>& currentRow=triangle[i];
            int m=currentRow.size();
            for(int j=0;j<m;j++)
            {
                int ans=triangle[i][j];
                int minAns=__INT_MAX__;
                if(j-1>=0) minAns=min(minAns,triangle[i-1][j-1]);
                if(j<m-1) minAns=min(minAns,triangle[i-1][j]);
                triangle[i][j]=triangle[i][j]+minAns;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,triangle[n-1][i]);
        }
        return ans;
    }
};