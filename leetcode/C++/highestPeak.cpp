#include <vector>
#include <queue>
using namespace std;
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<int> pair1;
        queue<int> pair2;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j]) {
                    ans[i][j]=0;
                    pair1.emplace(i);
                    pair2.emplace(j);
                }
            }
        }
        while (!pair1.empty())
        {
            int i=pair1.front();
            int j=pair2.front();
            pair1.pop();pair2.pop();
            for(int index=0;index<4;index++)
            {
                int x=i+dirs[index][0];int y=j+dirs[index][1];        
                if(x>=0&&x<m&&y>=0&&y<n&&ans[x][y]==-1)
                {
                    ans[x][y]=ans[i][j]+1;
                    pair1.emplace(x);
                    pair2.emplace(y);
                }
            }
        }
        return ans;
    }
};