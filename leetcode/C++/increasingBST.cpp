#include <stack>
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
    TreeNode* ans;TreeNode *tree;
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> s;
        while(root!=nullptr||!s.empty())
        {
           while(root!=nullptr)
           {
                s.push(root);
                root=root->left;
           }
           root=s.top();
           TreeNode* temp=root;
           s.pop();
           if(tree==nullptr) {tree=root;ans=root;}
           else{
                tree->right=root;
                tree=tree->right;
           }
           root=root->right;
           temp->left=nullptr;
           temp->right=nullptr;
        }
        return ans;
    }
};