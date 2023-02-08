#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        int length=words.size();
        vector<int> masks(length);
        for(int i=0;i<length;i++)
        {
            string s=words[i];
            int t=0;
            for(int j=0;j<s.length();j++)
            {
                int c=s[j]-'a';
                t|=(1<<c);
            }
            masks[i]=t;
        }
        for(int i=0;i<length;i++)
        {
            for(int j=i+1;j<length;j++)
            {
                if((masks[i]&masks[j])==0) {
                    int t=words[i].length()*words[j].length();
                    ans=max(ans,t);
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> words={"abcw","baz","foo","bar","fxyz","abcdef"};
    s.maxProduct(words);
}