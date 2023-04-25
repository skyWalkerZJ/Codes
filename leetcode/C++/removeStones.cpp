#include <vector>
using namespace std;
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> row(n,0);
        vector<int> col(n,0);
        for(vector<int> v:stones)
        {
            row[v[0]]++;
            col[v[1]]++;
        }
        int ans=0;
        for(vector<int> v:stones)
        {
            if(row[v[0]]>1 || col[v[1]]>1)
            {
                ans++;
                row[v[0]]--;
                col[v[1]]--;
            }
        }
        return ans;
    }
};