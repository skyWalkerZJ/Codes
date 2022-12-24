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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        int i=1;
        while(root!=nullptr||!stack.empty())
        {
            while(root!=nullptr)
            {
                stack.emplace(root);
                root=root->left;
            }
            root=stack.top();
            stack.pop();
            if(i==k) return root->val;
            root=root->right;
            i++;
        }
        return -1;
    }
};