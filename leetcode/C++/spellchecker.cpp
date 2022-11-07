#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> res;
        unordered_set<string> set;
        unordered_map<string,string> map1;
        unordered_map<string,string> map2;
        for(string s:queries)
        {
            set.emplace(s);
        }
        return res;
    }
};