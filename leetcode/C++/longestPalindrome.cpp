#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        int n=s.size();string ans;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n-1;i++)
        {
            dp[i][i]=true;
        }
        for(int L=2;L<=n;L++)
        {
            for(int i=0;i<n;i++)
            {
                int j=i+L-1;
                if(j>n) break;
                if(s[i]!=s[j]) continue;
                else{
                    if(j-i<3)
                    {
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]){
                    ans=s.substr(i,L);
                }
            }
        }
        
        if(ans=="") return s.substr(0,1);
        return ans;
    }
};
int main()
{
    string s="bb";
    Solution so;
    so.longestPalindrome(s);
    cout<<s.substr(0,2);
}