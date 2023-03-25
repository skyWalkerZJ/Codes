#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;int n=s.size();
        int leftCount=0;
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(c=='['||c=='{'||c=='(')
            {
                leftCount++;
                st.push(c);
            }else
            {
                if(leftCount==0) return false;
                if(c==']')
                {
                    if(st.top()=='[')
                    {
                        leftCount--;
                        st.pop();
                        continue;
                    }
                    return false;
                }else if(c=='}')
                {
                    if(st.top()=='{')
                    {
                        leftCount--;
                        st.pop();
                        continue;
                    }
                    return false;
                }else if(c==')')
                {
                    if(st.top()=='(')
                    {
                        leftCount--;
                        st.pop();
                        continue;
                    }
                    return false;
                }
            }
        }
        if(leftCount>0) return false;
        return true;
    }
};
int main()
{
    Solution s;
    s.isValid("()[]{}");
}