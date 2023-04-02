#include <string>
using namespace std;
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        if(s.size()<2) return 0;
        int sum=0;int ans=0;bool flag=false;
        int zeroSum=0,oneSum=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0'&&flag)
            {
                zeroSum++;
            }else if(s[i]=='0')
            {
                zeroSum=1;
                oneSum=0;
                flag=true;
            }else{
                oneSum++;
                ans=max(ans,min(zeroSum,oneSum));
                flag=false;
            }
        }
        return ans*2;
    }
};