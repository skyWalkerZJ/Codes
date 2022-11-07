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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        if(preorder.size()==1) return new TreeNode(preorder[0]);
        int base=preorder[0];
        TreeNode *root=new TreeNode(base);
        vector<int> leftTree;vector<int> rightTree;
        for(int i=1;i<preorder.size();i++)
        {
            if(preorder[i]<base) leftTree.push_back(preorder[i]);
            else rightTree.push_back(preorder[i]); 
        }
        root->left=bstFromPreorder(leftTree);
        root->right=bstFromPreorder(rightTree);
        return root;
    }
};