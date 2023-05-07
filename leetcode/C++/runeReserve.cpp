#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int runeReserve(vector<int>& runes) {
        sort(runes.begin(),runes.end());
        int ans=0;int n=runes.size();
        int count=0;int pre=-2;
        for(int i=0;i<n;i++)
        {
            if(runes[i]-pre>1)
            {
                count=1;
            }else{
                count++;
            }
            pre=runes[i];
            ans=max(ans,count);
        }
        return ans;
    }
};