#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
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

    //find the shortest prefix of the word in the tree
    string findPrefix(string word)
    {
        Trie* parent=this;
        string ans="";
        for(const char ch:word)
        {
            parent=parent->nextChar[ch-'a'];
            if(parent!=nullptr) 
            {
                ans.insert(ans.end(),ch);
                if(parent->ifEnd) return ans;
            }else break;
        }
        return word;
    }
};
class Solution {
public:
    //使用set实现
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


    //使用前缀树实现
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *trie=new Trie();
        for(auto itr=dictionary.begin();itr!=dictionary.end();itr++)
        {
            trie->insert(*itr);
        }
        vector<string> words=split(sentence,' ');
        string ans="";
        for(auto itr=words.begin();itr!=words.end();itr++)
        {
            string prefix=trie->findPrefix(*itr);
            ans.append(prefix);
            ans.append(" ");
        }
        return ans.substr(0,ans.size()-1);
    }
};

int main()
{
    Trie *trie=new Trie();
    trie->insert("apple");
    trie->insert("app");
    cout<<trie->findPrefix("appqweqwe");
}