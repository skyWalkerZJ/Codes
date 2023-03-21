#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> ans(amount+1,0);
        ans[0]=1;
        for(int i=1;i<=amount;i++)
        {
            int res=__INT_MAX__;
            for(int j=0;j<n;j++)
            {
                if(coins[j]<=i&&ans[i-coins[j]]!=__INT_MAX__)  res=min(res,ans[i-coins[j]]+1);
            }
            ans[i]=res;
        }
        if(ans[amount]==__INT_MAX__) return -1;
        return ans[amount]-1;
    }
};