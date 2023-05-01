#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> map;
        int m=mat.size();int n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                map[mat[i][j]]=pair<int,int>{i,j};
            }
        }
        vector<int> row(m,0);
        vector<int> col(n,0);

        for(int i=0;i<m*n;i++)
        {
            int target=arr[i];
            row[map[target].first]++;
            col[map[target].second]++;

            if(row[map[target].first]==n) return i;
            if(col[map[target].second]==m) return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> v={1,4,5,2,6,3};
    vector<vector<int>> m={{4,3,5},{1,2,6}};
    s.firstCompleteIndex(v,m);
}