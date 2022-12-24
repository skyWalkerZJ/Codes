#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++)
        {   
            int temp=i;
            for(int j=0;i<haystack.size()&&j<needle.size();j++)
            {
                if(haystack[i]!=needle[j])
                {
                    break;
                }
                i++;
            }
            if(i-temp==needle.size()) return temp;
            else i=temp;
        }
        return -1;
    }
};