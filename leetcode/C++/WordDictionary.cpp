#include <string>
#include <vector>
using namespace std;
class WordDictionary {
public:
    vector<WordDictionary*> dictionary;
    bool isEnd;
    WordDictionary() {
        vector<WordDictionary*> temp(26,NULL);
        dictionary=temp;
        this->isEnd=false;
    }
    
    void addWord(string word) {
        WordDictionary *root=this;
        for(char c:word)
        {
            c-='a';
            if(root->dictionary[c]==NULL)
            {
                root->dictionary[c]=new WordDictionary();
            }
            root=root->dictionary[c];
        }
        root->isEnd=true;
    }
    
    bool search(string word) {
         return dfs(word, 0, this);
    }

    bool dfs(const string & word,int index,WordDictionary * node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            WordDictionary * child = node->dictionary[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        } else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                WordDictionary * child = node->dictionary[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }
};