#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char,vector<char>> map;
        map.emplace('2',vector<char>{'a','b','c'});
        map.emplace('3',vector<char>{'d','e','f'});
        map.emplace('4',vector<char>{'g','h','i'});
        map.emplace('5',vector<char>{'j','k','l'});
        map.emplace('6',vector<char>{'m','n','o'});
        map.emplace('7',vector<char>{'p','q','r','s'});
        map.emplace('8',vector<char>{'t','u','v'});
        map.emplace('9',vector<char>{'w','x','y','z'});
        vector<vector<char>> v;
        queue<string> q;
        q.push("");
        for(char c:digits)
        {
            if(c!='1') v.push_back(map[c]);
        }
        if(v.size()==0) return vector<string>{};
        for(vector<char> vec:v)
        {
            int n=q.size();
            while(n>0)
            {
                string s=q.front();
                q.pop();
                for(char c:vec)
                {
                    string temp=s;
                    temp.insert(temp.end(),c);
                    q.push(temp);
                }
                n--;
            }
        }
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    s.letterCombinations("23");
}