#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Trie {
public:
    vector<Trie*> nextChar;
    bool ifEnd;
    int count=0;
    string str;
    /** Initialize your data structure here. */
    Trie() {
        vector<Trie*> tries(26,nullptr);
        this->nextChar=tries;
        this->ifEnd=false;
    }
    
    /** Inserts a word into the trie. */
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
        parent->str=word;
        parent->ifEnd=true;
        return parent;
    }

    Trie* startsWith(string prefix) {
        Trie* parent=this;
        for(auto ch:prefix)
        {
            parent=parent->nextChar[ch-'a'];
            if(parent==nullptr) return nullptr;
        }
        return parent;
    }
};
class MapSum {
public:
    Trie* trie;
    unordered_map<string,int> hashmap;
    MapSum() {
        this->trie=new Trie();
    }
    
    void insert(string key, int val) {
        trie->insert(key);
        hashmap[key]=val;
    }
    
    int sum(string prefix) {
        int ans=0;
        Trie* pre=trie->startsWith(prefix);
        stack<Trie*> stack;
        stack.emplace(pre);
        while(!stack.empty())
        {
            pre=stack.top();
            stack.pop();
            if(pre->ifEnd) ans+=hashmap[pre->str];
            if(pre->count!=0)
            {
                for(int i=0;i<26;i++)
                {
                    if(pre->nextChar[i]) stack.push(pre->nextChar[i]);
                }
            }
        }
        return ans;
    }
};