#include <string>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string ans="";
        stack<char> sk;
        for(char c:s)
        {
            if(c!=']') sk.push(c);
            else{
                string temp="";
                while(!sk.empty())
                {
                    char ch=sk.top();
                    sk.pop();
                    if(ch=='[') break;
                    temp.insert(temp.begin(),ch);
                }
                int flag=1;int sum=0;
                while(!sk.empty())
                {   
                    char ch=sk.top();
                    if(ch>='0' && ch<='9') {
                        sk.pop();
                        int t=ch-'0';
                        sum=t*flag+sum;
                        flag*=10;
                    }else{
                        break;
                    }
                }

                for(int i=0;i<sum;i++)
                {
                    for(char cha:temp)
                    {
                        sk.push(cha);
                    }
                }
            }
        }
        while(!sk.empty())
        {
            ans.insert(ans.begin(),sk.top());
            sk.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    //cout<<'9'-'0';
    cout<<s.decodeString("3[a2[c]]");
    
}