#include <vector>
#include <string>
using namespace std;
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    vector<string> dictionary;
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        this->dictionary=dictionary;
    }
    
    bool search(string searchWord) {
        for(string str:dictionary)
        {
            if(str.size()!=searchWord.size()) continue;
            int diff=0;
            for(int i=0;i<searchWord.size();i++)
            {
                if(searchWord[i]!=str[i]) diff++;
                if(diff>1) break;
            }
            if(diff<=1) return true;
        }
        return false;
    }
};