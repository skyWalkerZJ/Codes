#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return vector<int>{0};
        if(n==1) return vector<int>{0,1};
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        int flag=2;
        for(int i=2;i<=n;i++)
        {
            if(i==flag*2) flag*=2;
            ans.push_back(1+ans[i-flag]);
        }
        return ans;
    }
};