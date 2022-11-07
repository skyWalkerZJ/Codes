#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dictionart_set;
        string ans="";
        for(auto itr=dictionary.begin();itr!=dictionary.end();itr++)
        {
            dictionart_set.emplace(*itr);
        }
        vector<string> words=split(sentence,' ');
        for(auto itr=words.begin();itr!=words.end();itr++)
        {
            string temp=*itr;
            string word=temp;
            for(int i=0;i<temp.size();i++)
            {
                string str=temp.substr(0,i);
                auto search=dictionart_set.find(str);
                if(search!=dictionart_set.end())
                {
                    word=*search;
                    break;
                } 
            }
            ans.append(word);
            ans.append(" ");
        }
        return ans.substr(0,ans.size()-1);
    }

    vector<string> split(string &str, char ch) {
        int pos = 0;
        int start = 0;
        string s(str);
        vector<string> ret;
        while (pos < s.size()) {
            while (pos < s.size() && s[pos] == ch) {
                pos++;
            }
            start = pos;
            while (pos < s.size() && s[pos] != ch) {
                pos++;
            }
            if (start < s.size()) {
                ret.emplace_back(s.substr(start, pos - start));
            }
        }
        return ret;
    }
};