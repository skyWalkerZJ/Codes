#include <vector>
using namespace std;
class Solution {
public:
    Trie* root=new Trie();
    static const int HIGH_BIT=30; 
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<nums.size();i++)
        {
            add(nums[i-1]);
            ans=max(check(nums[i]),ans);
        }
        return ans;
    }

    void add(int num)
    {
        Trie* cur=root;
        for(int i=HIGH_BIT;i>=0;i--)
        {
            int bit=(num>>i) & 1;
            if(bit==0)
            {
                if(!cur->left)
                {
                    cur->left=new Trie();
                }
                cur=cur->left;
            }else{
                if(!cur->right)
                {
                    cur->right=new Trie();
                }
                cur=cur->right;
            }
        }
    }

    int check(int num)
    {
        Trie* cur=root;int x=0;
        for(int i=HIGH_BIT;i>=0;i--)
        {
            int bit=(num>>i) & 1;
            if(bit==0)
            {
                if(cur->right) {x=x*2+1;cur=cur->right;}
                else{cur=cur->left;x=x*2;}
            }else{
                if(cur->left) {x=x*2+1;cur=cur->left;}
                else{cur=cur->right;x=x*2;}
            }
        }
        return x;
    }
};
class Trie{
public:
    Trie* left=nullptr;//0
    Trie* right=nullptr;//1
    Trie(){}
};