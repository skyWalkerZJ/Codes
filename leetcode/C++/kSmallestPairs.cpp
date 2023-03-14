#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        auto greaterthan = 
            [&nums1, &nums2](pair<int, int> a, pair<int, int> b)->bool
            { return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };

        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(greaterthan)> que(greaterthan);
        int m = nums1.size();
        int n = nums2.size();
        // 1. 先将[i,0],0<=i<min(m,k)，放入堆中
        for (int i = 0; i < min(m, k); ++ i)
            que.emplace(i, 0); 
        
        vector<vector<int>> res;
        while (k -- && !que.empty())
        {
            auto& [i, j] = que.top();
            res.emplace_back(initializer_list<int>{nums1[i], nums2[j]});
            // 2. 后续解空间遍历，只需遍历[i,j+1]
            if (j+1 < n)
                que.emplace(i, j+1);
            que.pop();
        }
        return res;
    }
};