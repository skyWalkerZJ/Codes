#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size()/3;
        int ans=0;int trin=piles.size();
        for(int i=1;i<=n;i++)
        {
            ans+=piles[trin-i*2];
        }
        return ans;
    }
};