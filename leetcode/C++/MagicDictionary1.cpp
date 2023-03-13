#include <vector>
#include <string>
using namespace std;
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    Trie* trie;
    string searchWord;
    MagicDictionary() {
        this->trie=new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string s:dictionary) 
            trie->insert(s);
    }
    
    bool search(string searchWord) {
        this->searchWord=searchWord;
        return dfs(this->trie,0,false);
    }

    bool dfs(Trie* node,int pos,bool modified)
    {
        if(pos==searchWord.size()) return modified&&node->ifEnd;
        int index=searchWord[pos]-'a';
        if(node->nextChar[index])
        {
            if(dfs(node->nextChar[index],pos+1,modified))
            {
                return true;
            }
        }
        if(!modified)
        {
            for(int i=0;i<26;i++)
            {
                if(i!=index&&node->nextChar[i]) 
                {
                    if(dfs(node->nextChar[i],pos+1,true)) return true;
                }
            }
        }
        return false;
    }
};

class Trie {
public:
    vector<Trie*> nextChar;
    bool ifEnd;
    /** Initialize your data structure here. */
    Trie() {
        vector<Trie*> tries(26,nullptr);
        this->nextChar=tries;
        this->ifEnd=false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* parent=this;
        for(auto c:word)
        { 
            if(parent->nextChar[c-'a']==nullptr){
                Trie* sonTree=new Trie();
                parent->nextChar[c-'a']=sonTree;
            }
            parent=parent->nextChar[c-'a'];
        }
        parent->ifEnd=true;
    }
};