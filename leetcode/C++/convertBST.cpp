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
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;stack<TreeNode*> s;TreeNode* temp=root;
        while(!s.empty()||root!=nullptr)
        {
            while(root!=nullptr)
            {
                s.emplace(root);
                root=root->right;
            }
            root=s.top();
            s.pop();
            sum+=root->val;
            root->val=sum;
            root=root->left;
        }
        return temp;
    }
};