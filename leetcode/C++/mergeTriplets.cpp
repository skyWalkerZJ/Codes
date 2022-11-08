#include <vector>
using namespace std;
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> ans;
        int x=target[0];int y=target[1];int z=target[2];
        for(int i=0;i<triplets.size();i++)
        {
            if(triplets[i][0]<=x&&triplets[i][1]<=y&&triplets[i][2]<=z)
            ans.push_back(triplets[i]);
        }
        bool flag1=false,flag2=false,flag3=false;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i][0]==x) flag1=true;
            if(ans[i][1]==y) flag2=true;
            if(ans[i][2]==z) flag3=true;
        }
        return flag1&&flag2&&flag3;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> triplets;
    triplets.push_back(vector<int>{2,5,3});
    triplets.push_back(vector<int>{1,8,4});
    triplets.push_back(vector<int>{1,7,5});
    vector<int> target{2,7,5};
    s.mergeTriplets(triplets,target);
}