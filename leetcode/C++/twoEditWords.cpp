#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string s:queries)
            for(string t:dictionary)
            {
                int count=0;
                for(int i=0;i<s.length();i++)if(s[i]!=t[i]) count++;
                if(count<=2) {ans.push_back(s);break;}
            }
        return ans;
    }
};