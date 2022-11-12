#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto itr=wordDict.begin();itr!=wordDict.end();itr++)
        {   
            set.insert(*itr);
        }
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.length();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]&&set.count(s.substr(j,i-j))>0)
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};