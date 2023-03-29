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
    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        backtrack(root,q);TreeNode* end;
        while (!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(end==nullptr) end=node;
            else{
                end->right=node;
                end=end->right;
            }
            end->left=nullptr;
            end->right=nullptr;
        }
        return;
    }

    void backtrack(TreeNode* root,queue<TreeNode*>& q)
    {
        q.emplace(root);
        if(root->left) backtrack(root->left,q);
        if(root->right) backtrack(root->right,q);
    }
};