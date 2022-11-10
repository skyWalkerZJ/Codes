#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <iostream>
using namespace std;
bool compare(string s1,string s2)
{
    if(s1.length()!=s2.length()) return s1.length()<s2.length();
    return s1<s2;
}
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        unordered_set<string> hashset;
        string ans=words[0];
        hashset.insert("");
        for(auto itr=words.begin();itr!=words.end();itr++)
        {
            
            string last=(*itr).substr(0,(*itr).length()-1);
            if(hashset.count(last)>0&&(*itr).length()>ans.length()) {ans=*itr;}
            if(hashset.count(last)>0) hashset.insert(*itr);
        }
        return ans;
    }
};
int main()
{
    vector<string> test={"yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"};
    Solution s;
    cout<<s.longestWord(test);
}