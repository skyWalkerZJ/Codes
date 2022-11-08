#include <queue>
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
    int sumNumbers(TreeNode* root) {
        int ans=0;
        queue<TreeNode *> tree;
        tree.push(root);
        while(!tree.empty())
        {
            TreeNode* currentNode=tree.front();
            tree.pop();
            if(currentNode->left==NULL&&currentNode->right==NULL) ans+=currentNode->val;
            else{
                if(currentNode->left!=NULL)
                {
                    currentNode->left->val=currentNode->val*10+currentNode->left->val;
                    tree.push(currentNode->left);
                }
                if(currentNode->right!=NULL)
                {
                    currentNode->right->val=currentNode->val*10+currentNode->right->val;
                    tree.push(currentNode->right);
                }
            }
        }
        return ans;
    }
};