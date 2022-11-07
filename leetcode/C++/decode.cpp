#include <vector>
using namespace std;
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        if(encoded.size()==0) return vector<int>{};
        int n=encoded.size()+1;
        int odd=0;
        for(int i=1;i<=n;i++)
        {
            odd^=i;
        }
        int odd1=0;
        for(int i=1;i<n-1;i+=2)
        {
            odd1^=encoded[i];
        }
        vector<int> ans;
        ans.push_back(odd^odd1);
        for(int i=0;i<encoded.size();i++)
        {
            ans.push_back(ans[i]^encoded[i]);
        }
        return ans;
    }
};