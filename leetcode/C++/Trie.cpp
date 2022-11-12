#include <string>
#include <vector>
using namespace std;
class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* root=this;
        for(char ch:prefix)
        {
            ch=ch-'a';
            if(root->children[ch]==NULL)
            return NULL;
            root=root->children[ch];
        }
        return root;
    }
public:
    Trie() {
        vector<Trie*> child(26,NULL);
        children=child;
        isEnd=false;
    }
    
    void insert(string word) {
        Trie* root=this;
        for(char ch:word)
        {
            ch-='a';
            if(root->children[ch]==NULL)
            {
                root->children[ch]=new Trie();
            }
            root=root->children[ch];
        }
        root->isEnd=true;
    }
    
    bool search(string word) {
        Trie* node=searchPrefix(word);
        return node!=NULL&&node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix)!=NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */