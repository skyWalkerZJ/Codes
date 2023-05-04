#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    //392 判断子序列
    bool isSubsequence(string s, string t) {
        int n=s.size();int m=t.size();
        vector<vector<int>> dp(m+1,vector<int>(26,0));
        for(int i=0;i<26;i++)
        {
            dp[m][i]=m;
        }

        for(int i=m-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
            {
                if(t[i]=='a'+j)
                {
                   dp[i][j]=i; 
                }else{
                    dp[i][j]=dp[i+1][j];
                }
            }
        }
        int pre=0;
        for(int i=0;i<n;i++)
        {
            if(dp[pre][s[i]-'a']==m) return false;
            pre=dp[pre][s[i]-'a']+1;
        }
        return true;
    }
};