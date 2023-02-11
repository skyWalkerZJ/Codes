#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> dictionary;
        int left=0;int right=0;int n=s.length();
        int ans=0;
        for(;right<n;right++)
        {
            if(dictionary.find(s[right])==dictionary.end()) dictionary.insert(pair<char,int>{s[right],right});
            else{
                if(dictionary[s[right]]<left) {
                    dictionary[s[right]]=right;
                }else{
                    left=dictionary[s[right]]+1;
                    dictionary[s[right]]=right;
                }
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};