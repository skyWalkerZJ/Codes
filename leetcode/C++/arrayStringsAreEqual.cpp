#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int p1=0,p2=0,i=0,j=0;
        while(p1<word1.size()&&p2<word2.size())
        {
            string &s1=word1[p1];
            string &s2=word2[p2];
            while(i<s1.size()&&j<s2.size())
            {
                if(s1[i]!=s2[j]) return false;
                else{
                    i++;j++;
                }
            }
            if(i==s1.size())
            {
                p1++;i=0;
            }
            if(j==s2.size())
            {
                p2++;j=0;
            }
        }
        return p1==word1.size()&&p2==word2.size();
    }
};