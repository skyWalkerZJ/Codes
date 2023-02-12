#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        int left=0;int right=s.size()-1;
        while(left<right)
        {
            if(s[left]==s[right])
            {
                left++;right--;
                continue;
            }
            else {
                return ifPalindrome(s.substr(left+1,right-left))||ifPalindrome(s.substr(left,right-left));
            }
        }
        return true;
    }
    bool ifPalindrome(string s)
    {
        int left=0;int right=s.size()-1;
        while(left<right)
        {
            if(s[left]!=s[right]) return false;
            left++;right--;
        }
        return true;
    }
};
int main()
{
    Solution s;
    cout<<s.validPalindrome("abcca");
}