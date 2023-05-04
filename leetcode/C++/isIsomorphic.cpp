#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();int m=t.size();
        if(m!=n) return false;
        unordered_map<char,char> left;
        unordered_map<char,char> right;
        
        for(int i=0;i<n;i++)
        {
            if(left.count(s[i])==0 && right.count(t[i])==0)
            {
                left[s[i]]=t[i];
                right[t[i]]=s[i];
            }else if(left.count(s[i])!=0 && right.count(t[i])!=0)
            {
                if(left[s[i]]==t[i]&&right[t[i]]==s[i]) continue;
                else return false;
            }else {
                return false;
            }
        }
        return true;
    }
};