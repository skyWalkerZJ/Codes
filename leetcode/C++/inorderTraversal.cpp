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
    //Morris 中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;TreeNode* preDecessor=NULL;
        while(root!=NULL)
        {
            if(root->left!=NULL)
            {
                preDecessor=root->left;
                while(preDecessor->right!=root&&preDecessor->right!=NULL)
                {
                    preDecessor=preDecessor->right;
                }
                if(preDecessor->right==NULL)
                {
                    preDecessor->right=root;
                    root=root->left;
                }else{
                    ans.push_back(root->val);
                    preDecessor->right=NULL;
                    root=root->right;
                }
            }else{
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};