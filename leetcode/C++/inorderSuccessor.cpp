#include <stack>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;bool flag=false;
        while(root!=nullptr||!s.empty())
        {
            while(root!=nullptr)
            {
                s.emplace(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(flag) return root;
            if(root==p){
                flag=true;
            }
            root=root->right;
        }
        return nullptr;
    }
};