#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool valid(string s)
    {
        int banlance=0;
        for(char ch:s)
        {
            if(ch=='(')
            banlance++;
            else if(ch==')')
            banlance--;

            if(banlance<0) return false;
        }
        return banlance==0;
    }

    void generate_all(string& current,int n,vector<string>& result)
    {
        if(current.size()==n)
        {
            if(valid(current))
            {
                result.push_back(current);
            }
            return;
        }

        current+="(";
        generate_all(current,n,result);
        current.pop_back();
        current+=")";
        generate_all(current,n,result);
        current.pop_back();
    }

    void backtrack(vector<string>& ans,int open,int close,int n,string& current)
    {
        if(current.size()==n*2)
        {
            ans.push_back(current);
            return;
        }
        if(open<n)
        {
            current+="(";
            backtrack(ans,open+1,close,n,current);
            current.pop_back();
        }
        if(close<open)
        {
            current+=")";
            backtrack(ans,open,close+1,n,current);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result,0,0,n,current);
        return result;   
    }
};