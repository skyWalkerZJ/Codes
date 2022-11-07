#include <vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums,0,nums.size()-1);
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums,int begin,int end) {
        if(begin>end||end<0||begin>nums.size()-1) return NULL;
        if(begin==end) return new TreeNode(nums[begin]);
        int maxPos=getMax(nums,begin,end);int max=nums[maxPos];
        TreeNode *root=new TreeNode(max);
        root->left=constructMaximumBinaryTree(nums,begin,maxPos-1);
        root->right=constructMaximumBinaryTree(nums,maxPos+1,end);
        return root;
    }
    int getMax(vector<int>&num,int begin,int end)
    {
        int max=-1;int ans=-1;
        for(int i=begin;i<=end;i++)
        {
            if(num[i]>max) {max=num[i];ans=i;}
        }
        return ans;
    }
};