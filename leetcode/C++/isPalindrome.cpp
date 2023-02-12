#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;int right=s.size()-1;
        while(left<right)
        {
            if(!ifNumOrChar(s[left])) {
                left++;
                continue;
            }
            if(!ifNumOrChar(s[right])) {
                right--;
                continue;
            }
            if(!ifSame(s[left],s[right])) return false;
            left++;right--;
        }
        return true;
    }

    bool ifNumOrChar(char c)
    {
        if((c<='z'&&c>='a')||(c<='Z'&&c>='A')||(c>='0'&&c<='9')) return true;
        return false;
    }
    bool ifSame(char left,char right)
    {
        if(left==right) return true;
        else if(max(left,right)-min(left,right)==32&&((left<='z'&&left>='a')||(left<='Z'&&left>='A'))&&((right<='z'&&right>='a')||(right<='Z'&&right>='A'))) return true;
        return false;
    }
};
int main()
{
    Solution s;
    cout<<s.ifSame('0','P');
    cout<<'A'-'a';
}