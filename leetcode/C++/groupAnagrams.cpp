#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashmap;
        for(auto s:strs)
        {
            string t=s;
            sort(t.begin(),t.end());
            hashmap[t].emplace_back(s);
        }
        vector<vector<string>> ans;
        for(auto itr=hashmap.begin();itr!=hashmap.end();itr++)
        {
            ans.emplace_back(itr->second);
        }
        return ans;
    }
};