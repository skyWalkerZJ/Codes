#include <vector>
#include <string>
using namespace std;
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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* parent=this;
        for(auto ch:word)
        {
            parent=parent->nextChar[ch-'a'];
            if(parent==nullptr) return false; 
        }
        return parent->ifEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* parent=this;
        for(auto ch:prefix)
        {
            parent=parent->nextChar[ch-'a'];
            if(parent==nullptr) return false;
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
}