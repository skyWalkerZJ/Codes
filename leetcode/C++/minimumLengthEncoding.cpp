#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Trie {
public:
    vector<Trie*> nextChar;
    bool ifEnd;
    int count;
    Trie() {
        vector<Trie*> tries(26,nullptr);
        this->nextChar=tries;
        this->ifEnd=false;
        this->count=0;
    }
    
    Trie* insert(string word) {
        Trie* parent=this;
        for(auto c:word)
        { 
            if(parent->nextChar[c-'a']==nullptr){
                Trie* sonTree=new Trie();
                parent->nextChar[c-'a']=sonTree;
                parent->count++;
            }
            parent=parent->nextChar[c-'a'];
        }
        parent->ifEnd=true;
        return parent;
    }
};
class Solution {
public:
    Trie* trie;
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<Trie*,int> map;
        this->trie=new Trie();
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            reverse(s.begin(),s.end());
            Trie* parent=trie->insert(s);
            map.emplace(parent,i);
        }
        int ans=0;
        for(auto itr=map.begin();itr!=map.end();itr++)
        {
            if((*itr).first->count==0) ans+=words[(*itr).second].size()+1;
        }
        return ans;
    }
};