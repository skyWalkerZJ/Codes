#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hashmap;
        int i=0;
        for(char ch:s)
        {
            if(!hashmap.count(ch))
            {
                hashmap.insert(pair<char,int>{ch,i});
            }else{
                hashmap[ch]=-1;
            }
            i++;
        }
        int ans=INT32_MAX;
        for(auto itr=hashmap.begin();itr!=hashmap.end();itr++)
        {
            if(itr->second==-1) continue;
            else ans=min(ans,itr->second);
        }
        return ans==INT32_MAX?-1:ans;
    }
};