#include <vector>
using namespace std;
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6,1.0/6.0);
        for(int i=2;i<=n;i++)
        {
            int m=dp.size();
            vector<double> temp(i*6-i+1,0);
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<6;j++)
                {
                    temp[i+j]+=dp[i]*(1.0/6.0);
                }
            }
            dp=temp;
        }
        return dp;
    }
};
int main()
{
    Solution s;
    s.dicesProbability(11);
}