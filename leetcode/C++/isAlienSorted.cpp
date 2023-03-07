#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> dictionary;
        for(int i=0;i<order.size();i++)
        {
            dictionary[order[i]]=i;
        }

        for(int i=0;i<words.size()-1;i++)
        {
            if(compare(words[i],words[i+1],dictionary)==false) return false;
        }
        return true;
    }

    bool compare(string s1,string s2,unordered_map<char,int> dictionary)
    {
        int n1=s1.size();int n2=s2.size();
        for(int i=0;i<n1&&i<n2;i++)
        {
            if(dictionary[s1[i]]<dictionary[s2[i]]) return true;
            else if(dictionary[s1[i]]>dictionary[s2[i]]) return false;
        }
        return n1<=n2;
    }
};