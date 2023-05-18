#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size();int m=matrix[0].size();
        int left=0;int right=m-1;
        int up=0;int down=n-1;
        int size=n*m;
        int i=0;int j=0;
        while(size>0)
        {
            //右
            while(j<=right&&size>0)
            {
                ans.push_back(matrix[i][j]);
                j++;
                size--;
            }
            j--;
            i++;
            up++;
            //下
            while(i<=down&&size>0)
            {
                ans.push_back(matrix[i][j]);
                i++;
                size--;
            }
            i--;
            j--;
            right--;
            //左
            while(j>=left&&size>0)
            {
                ans.push_back(matrix[i][j]);
                j--;
                size--;
            }
            j++;
            i--;
            down--;
            //上
            while(i>=up&&size>0)
            {
                ans.push_back(matrix[i][j]);
                i--;
                size--;
            }
            i++;
            j++;
            left++;
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> v{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution s;
    s.spiralOrder(v);
}