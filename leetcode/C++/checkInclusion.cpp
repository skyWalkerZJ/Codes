#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int masks1[26]={0},masks2[26]={0};int n=s1.length();
        for(int i=0;i<s1.length();i++)
        {
            masks1[s1[i]-'a']++;
        }
        int left=0;int right=0;
        for(;right<s2.length();right++)
        {   
            masks2[s2[right]-'a']++;
            if(equal(begin(masks1),end(masks1),begin(masks2))) return true;
            if(right-left+1==s1.length())
            {
                masks2[s2[left]-'a']--;
                left++;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    s.checkInclusion("ab","eidbaooo");
}