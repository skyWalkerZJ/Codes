#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int masks1[26]={0},masks2[26]={0};int n=p.length();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            masks1[p[i]-'a']++;
        }
        int left=0;int right=0;
        for(;right<s.length();right++)
        {   
            masks2[s[right]-'a']++;
            if(equal(begin(masks1),end(masks1),begin(masks2))) ans.push_back(left);
            if(right-left+1==n)
            {
                masks2[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};