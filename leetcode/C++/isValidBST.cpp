#include <stack>
#include <iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//验证搜索二叉树
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;long pre=LONG_MIN;
        while(!stack.empty()||root!=nullptr)
        {
            while(root!=nullptr)
            {
                stack.emplace(root);
                root=root->left;
            }
            root=stack.top();
            stack.pop();
            if(root->val<=pre) return false;
            pre=root->val;
            root=root->right;
        }
        return true;
    }
};