#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
struct cmp{
    bool operator ()(const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.second>b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> p;
        for(auto n:nums)
        {
            hashmap[n]++;
        }

        for(auto iter=hashmap.begin();iter!=hashmap.end();iter++)
        {
            pair<int,int> pair=*iter;
            p.push(pair);
            if(p.size()>k) p.pop();
        }

        vector<int> ans;
        while(!p.empty())
        {
            pair<int,int> pair=p.top();
            ans.push_back(pair.first);
            p.pop();
        }
        return ans;
    }
};