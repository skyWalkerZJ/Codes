#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans=0;unordered_set<char> set;
        set.emplace('a');
        set.emplace('e');
        set.emplace('i');
        set.emplace('o');
        set.emplace('u');
        for(int i=left;i<=right;i++)
        {
            int size=words[i].size();
            if(set.count(words[i][0])&&set.count(words[i][size-1])) ans++;
        }
        return ans;
    }
};