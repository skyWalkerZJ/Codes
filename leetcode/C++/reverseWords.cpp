#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ') continue;
            int start=i;
            while(s[i]!=' ')
            {
                i++;
            }
            string temp=s.substr(start,i-start);
            temp+=" ";
            ans=temp+ans;
        }
        int size=ans.size();
        return ans.substr(0,size-1);
    }
};